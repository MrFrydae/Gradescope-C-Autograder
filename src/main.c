#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

FILE *result_file;
bool is_first_test = true;

void checkOneThing(char *test_name, bool assert, int points_possible, char *error_message){
    char output[300];
    if (!is_first_test) {
        fprintf(result_file, ",\n");
    } else{
        is_first_test = false;
    }
    if(assert) {
        sprintf (output, "\t\t{\n"
                         "\t\t\t\"score\": %d, \n"
                         "\t\t\t\"max_score\": %d, \n"
                         "\t\t\t\"status\": \"passed\", \n"
                         "\t\t\t\"name\": \"%s\", \n"
                         "\t\t\t\"name_format\": \"text\"\n"
                         "\t\t}", points_possible, points_possible,test_name);
    } else
    {
        sprintf (output, "\t\t{\n"
                         "\t\t\t\"score\": %d, \n"
                         "\t\t\t\"max_score\": %d, \n"
                         "\t\t\t\"status\": \"failed\", \n"
                         "\t\t\t\"name\": \"%s\", \n"
                         "\t\t\t\"name_format\": \"text\",\n "
                         "\t\t\t\"output\": \"%s\""
                         "\n\t\t}", 0, points_possible,test_name,error_message);
    }
    fprintf( result_file, "%s", output );
}

int main() {

    result_file = fopen("output.json","w");
    assert(result_file != NULL);

    fprintf(result_file, "{  \"visibility\": \"after_due_date\", \n"
                       "  \"stdout_visibility\": \"visible\", \n"
                       "  \"tests\": [\n");
#include "test_details.h"
    fprintf(result_file, " ]}");
    fclose(result_file);
    return 0;
}
