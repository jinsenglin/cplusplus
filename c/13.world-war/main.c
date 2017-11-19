#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
Input
The first line of the input contains four things: 

1. The rows of the map (0 < rows < 100)

2. The columns of the map (0 < cols < 100)

3. The total length of instructions (0 < instructions's length < 100)

4. The initial tank's direction(N, S, E, W)

The second line is the content of instructions.

For the next lines, they illustrate the map.

Output
The number of military informations you get. (printf "\n" in the end)

Sample Input
6 8 10 N
JFFRJFFJRJ
########
#=^$^==#
#=xox==#
#$OOO$$#
#=OOO==#
########

Sample Output
2
*/

#define EAST 0
#define SOUTH 1
#define WEST 2
#define NORTH 3

char map[100][100];
char actions[100]={};
int coin_amount = 0;

// tank's initial direction
char init_dir;
// tank's direction now
int dir_now;
// tank's center x and y
int center_x, center_y;

void decide_initial_direction()
{
    /// Decide tank's initial direction
    /// Using init_dir
    /// To determine dir_now

    // 
    // XOX
    // OCO
    // XOX
    //
    
    if (init_dir == 'N') {
        dir_now = NORTH;
    }
    else if (init_dir == 'E') {
        dir_now = EAST;
    }
    else if (init_dir == 'S') {
        dir_now = SOUTH;
    }
    else if (init_dir == 'W') {
        dir_now = WEST;
    }
}

bool check_if_hit_wall_if_move_forward() {
    // TODO
    return false;
}

bool check_if_hit_hill_if_move_forward() {
    // TODO
    return false;
}

void take_a_step()
{
    if (dir_now == NORTH){
        /// Detect wall first
        if ( check_if_hit_wall_if_move_forward() ){
            // Do nothing
            return;
        }
        /// And then detect hill
        else if ( check_if_hit_hill_if_move_forward() ) {
            // Do nothing
            return;
        }
        /// If there is no obstacle, take a step
        else {
            // TODO
        }
    }
    else if (dir_now == SOUTH){
        // TODO
    }
    else if (dir_now == EAST){
        // TODO
    }
    else if (dir_now == WEST){
        // TODO
    }
}

void pick_the_coins()
{
    int j, k;
    for (j = center_x - 1; j <= center_x + 1; j++){
        for (k = center_y - 1; k <= center_y + 1; k++){
            /// determine whether there are coins under the tank
            // TODO
        }
    }
}

void turn_right()
{
    /// Change direction depending on dir_now
    // TODO
}

 

void turn_left()
{
    /// Change direction depending on dir_now
    // TODO
}

int main()
{
    int i, j, k, rows, cols;
    int actions_number;
    int component = 0;

    /// Raed problem's input
    scanf("%d %d %d %c", &rows, &cols, &actions_number, &init_dir);
    while (getchar() != '\n');
    for (i = 0; i < actions_number; i++){
        scanf("%c", &actions[i]);
    }

    /// Read map
    for (i = 1; i <= rows; i++){
        while (getchar() != '\n');
        for (j = 1; j <= cols; j++){
            scanf("%c", &map[i][j]);
            /// Find tank's center x and y
            if (((map[i][j]) == 'x') || ((map[i][j]) == 'o') || ((map[i][j]) == 'O')){
                component++;
                if (component == 5){
                    center_x = i;
                    center_y = j;
                }
            }
        }
    }

    decide_initial_direction();

    for (i = 0; i < actions_number; i++){
        if (actions[i] == 'F'){
            take_a_step();
            pick_the_coins();
        }

        else if (actions[i] == 'J'){

           /* TODO : Implement the instruction "J" here */
            printf("DEBUG: TODO - either take 2 F steps or do nothing.");
            

       }         
        else{
            if (actions[i] == 'R'){
                turn_right();
            }
            if (actions[i] == 'L'){
                turn_left();
            }
        }
    }

    printf("%d\n", coin_amount);

    return 0;
}
