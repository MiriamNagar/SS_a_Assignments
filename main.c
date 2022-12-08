#include <stdio.h>
#include "my_mat.h"


int main(){
    int mat[10][10] ={0}; //creating matrix to use
    char current_action = 'D'; //in case theres no input than finish program
    int flag = 1; 


    while(flag){ 
        scanf("%c", &current_action); //get char to know which operation to do
        if(current_action == 'A')
        {
            build_matrix(mat);

        }
        if(current_action == 'B')
        {
            int i=0, j=0; 
            scanf("%d%d", &i, &j); //scans values to check path from i to j
            path_exists(i, j); //checks for path

        }
        if(current_action == 'C')
        {
            int i=0, j=0;
            scanf("%d%d", &i, &j); //scans values to check path from i to j
            shortest_path(i, j);
        }
        if(current_action == 'D')
        {
            flag = 0; //than finish loop, and thus the program
        }
    }
}
