#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input_filename[]="crime_scene_report.csv";
    char output_filename[]="crime_scene_report_out.csv";
    FILE *input_file;
    FILE *output_file;
    char line1[2028];
    char line2[1024];
    input_file= fopen(input_filename, "r");
    output_file= fopen(output_filename, "w");
    if (input_file == NULL)
    {
        printf("Could not open file %s",input_filename);
        return 1;
    }
    if (output_file == NULL)
    {
        printf("Could not open file %s",output_filename);
        return 1;
    }
    int count = 0;
    while (fgets(line1, 1024, input_file))
    {
        count++;
        if(count >=47)
        {
            fgets(line2, 1024,input_file);
            line1[strlen(line1)-1] = ' ';
            strcat(line1, line2);
        }
        fputs(line1, output_file);
    }
    fclose(input_file);
    fclose(output_file);
    input_file = fopen(output_filename, "r");
    if(input_file == NULL)
    {
        printf("Could not open file %s",output_filename);
        return 1;
    }
    output_file = fopen("result.csv", "w");
    if(output_file == NULL)
    {
        printf("Could not open file result.csv");
        return 1;
    }
    while(fgets(line1, 1024, input_file)) {
        int index = 0;
        int i;
        for( i = (int)strlen(line1)-1;i>=0 && index == 0;i--)
        {
            if(line1[i] == ',')
            {
                index = i;
            }
        }
        int comma_count = 0;
        for(i = 0; i < strlen(line1); i++)
        {
            if(line1[i] == ',')
            {
                comma_count++;
                if(comma_count>2 )
                {
                    if(i<index)
                    {
                        line1[i] = ' ';
                    }
                }
            }

        }
        fputs(line1, output_file);
    }
    fclose(input_file);
    fclose(output_file);
}