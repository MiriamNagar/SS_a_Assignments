#include <stdio.h>
#include "my_mat.h"


int main(){
    int mat[10][10] ={};
    char current_action = 'D';
    int flag = 1;


    while(flag){
        scanf("%c", &current_action);
        if(current_action == 'A')
        {
            build_matrix(mat);

        }
        if(current_action == 'B')
        {
            path_exists();

        }
        if(current_action == 'C')
        {
            shortest_path();
        }
        if(current_action == 'D')
        {
            flag = 0;
        }
    }
}