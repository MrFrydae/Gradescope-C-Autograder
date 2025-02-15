#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "test_tools.h"

FILE *result_file;
bool is_first_test = true;

void checkOneThing(char *test_name, bool assert, int points_possible, char *error_message){
    char output[300];

    if (!is_first_test)
    {
        fprintf(result_file, ",\n");
    }
    else
    {
        fprintf(result_file, "[");

        is_first_test = false;
    }

    if(assert)
    {
        sprintf (output, "{\"score\": %d, \"max_score\": %d, \"status\": \"passed\", \"name\": \"%s\", \"name_format\": \"text\"}", points_possible, points_possible,test_name);
    }
    else
    {
        sprintf (output, "{\"score\": %d, \"max_score\": %d, \"status\": \"failed\", \"name\": \"%s\", \"name_format\": \"text\", \"output\": \"%s\"}", 0, points_possible,test_name,error_message);
    }

    fprintf( result_file, "%s", output );
}

int main() {
    result_file = fopen("output.json","w");
    assert(result_file != NULL);

#include "test_details.h"
    fprintf(result_file, "]");
    fclose(result_file);
    return 0;
}
