import json
import sys
import argparse

from typing import Optional

class TestResult:
    def __init__(self, score: int, max_score: int, status: str, name: str, name_format: str, output: Optional[str] = None):
        self.score = score
        self.max_score = max_score
        self.status = status
        self.name = name
        self.name_format = name_format
        self.output = output

class AutograderOutput:
    def __init__(self, visibility: str, stdout_visibility: str, tests: list[TestResult]):
        self.visibility = visibility
        self.stdout_visibility = stdout_visibility
        self.tests = tests

# Initialize parser
parser = argparse.ArgumentParser()

# Adding optional argument
parser.add_argument("-o", "--output", help = "Autograder output json file")
parser.add_argument("-l", "--linter", help = "Linter output file")
parser.add_argument("-lc", "--lintercode", help = "Linter code")
parser.add_argument("-lp", "--linterpoints", help = "Linter points")

# Read arguments from command line
args = parser.parse_args()

test_results = []

with open(args.linter, 'r') as file:
    test_results.append(TestResult(
        score=int(args.linterpoints) if args.lintercode==0 else 0,
        max_score=int(args.linterpoints),
        status='passed' if args.lintercode==0 else 'failed',
        name='Linter',
        name_format='text',
        output=file.read()
    ))

with open(args.output, 'r') as file:
    data = json.loads(file.read())

    for test in data:
        test_results.append(TestResult(
            score=test['score'],
            max_score=test['max_score'],
            status=test['status'],
            name=test['name'],
            name_format=test['name_format'],
            output=test.get('output')
        ))

    output = AutograderOutput("visible", "visible", test_results)

    print(json.dumps(output, default=lambda o: o.__dict__, indent=4))



