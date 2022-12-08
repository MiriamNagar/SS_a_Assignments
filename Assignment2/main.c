#include <stdio.h>
#include "my_mat.h"


int main(){
    int mat[10][10];
    char current_action;
    int flag = 1;


    while(flag){
        scanf("%c", &current_action);
        if(current_action == 'A')
        {
            build_matrix(mat);
            // print_matrix(mat);

        }
        if(current_action == 'B')
        {
            path_exists();//mat);
            // print_matrix(mat);

        }
        if(current_action == 'C')
        {
            shortest_path();//mat);
        }
        if(current_action == 'D')
        {
            flag = 0;
        }
    }
}