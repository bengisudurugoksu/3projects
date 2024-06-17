#include <stdio.h>
#include <string.h>//Declaring string.h.Used in part1.
#include <math.h>//Used in part2.

int part1();
int part2();
int part3();
int main(){
part1();
part2();
part3();
}
//PART1
int part1(){
int count[26]={0};
FILE* ptr;
char filename[50],text[100];
printf("Enter the file name: ");        //Getting the file name from the user.
scanf("%s", filename);
printf("\n");
ptr = fopen( filename, "r");	
if (NULL == ptr) {
	printf("The file can not be opened! \n");   //Printing an error message and getting the name once again if the file does not exist.
	printf("Please enter the file name again: ");
	scanf("%s", filename);
	printf("\n");
	ptr = fopen( filename, "r");	
	}
	while(!feof(ptr)){
		for(int i=0; i<100;i++){
		text[i]=fgetc(ptr);
		}
	}
	
	for(int j=0;j<100;j++){
		if(text[j]>= 'A' && text[j] <= 'Z'){   //If the letter is upper case we change it's value to the letter's lower case and we increase the letter's frequency.
			text[j] += 32;
			count[ text[j] - 'a']++;
		}
		else if(text[j] >= 'a' && text[j] <= 'z'){
			count[ text[j] - 'a']++;
		}
	}
	printf("Letter Frequency: \n");   //Printing each letter's frequency.
	for(int n=0; n<26; n++){
		printf("%c: %d\n", 'A'+n, count[n]);
	}


fclose(ptr);


return 0;
}
int part2(){
// Defining the Color enumeration type.
enum Color {
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE
};

// Defining the vectors for each color.
const double r[] = {1, 0, 0};
const double g[] = {0, 1, 0};
const double b[] = {0, 0, 1};
const double y[] = {0.5, 0.5, 0};
const double o[] = {0.5, 0.4, 0.2};

// Calculating the Euclidean Distance between two colors.
double euclidean_distance(double a[],  const double b[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

// Mixing two colors and returning the closest color using an Color function.
enum Color mix_colors(enum Color c1, enum Color c2) {
    const double* color1;
    const double* color2;
    switch (c1) {
        case RED:   //Declaring c1 and c2 as Color using switch case.
            color1 = r;
            break;
        case GREEN:
            color1 = g;
            break;
        case BLUE:
            color1 = b;
            break;
        case YELLOW:
            color1 = y;
            break;
        case ORANGE:
            color1 = o;
            break;
    }
    switch (c2) {
        case RED:
            color2 = r;
            break;
        case GREEN:
            color2 = g;
            break;
        case BLUE:
            color2 = b;
            break;
        case YELLOW:
            color2 = y;
            break;
        case ORANGE:
            color2 = o;
            break;
    }
    double mixed_color[3] = {(color1[0] + color2[0]) / 2,
                             (color1[1] + color2[1]) / 2,
                             (color1[2] + color2[2]) / 2};
    enum Color closest_color;
    double closest_distance = INFINITY;
    for (int count = 0; count < 5; count++) {
        const double* color;
        switch (count) {
            case RED:
                color = r;
                break;
            case GREEN:
                color = g;
                break;
            case BLUE:
                color = b;
                break;
            case YELLOW:
                color = y;
                break;
            case ORANGE:
                color = o;
                break;
        }
        double distance = euclidean_distance(mixed_color, color, 3);
        if (distance < closest_distance) {   //closest_distance is declared as INFINITY.If distance is smaller, we equalize closest_distance to distance.This way closest_distance is used like a temp value.Using this we found the smallest value and equalize it to count which shows the enum value of the color.
            closest_distance = distance;
            closest_color = count;
        }
    }
    return closest_color;
}

// Defining the colorMixer function.
enum Color colorMixer(enum Color c1, enum Color c2, enum Color (*mix)(enum Color, enum Color)) { 
    return mix(c1, c2);  //Returning the function pointer.
}
void control(enum Color mixed_color){  //Control function is used to print the closest color.
    switch(mixed_color){
    case 0:
    printf("Mixed color: RED[1.0, 0.0, 0.0]");
    break;
    case 1:
    printf("Mixed color: GREEN[0.0, 1.0, 0.0]");
    break;
    case 2:
    printf("Mixed color: BLUE[0.0, 0.0, 1.0]");
    break;
    case 3:
    printf("Mixed color: YELLOW[0.5, 0.5, 0.0]");
    break;
    case 4:
    printf("Mixed color: ORANGE[0.5, 0.4, 0.2]");
    break;
    }
    }
    char color1, color2;  //Getting the colors from the user to mix them.
    printf("Enter Color 1 (r,g,b,y,o): ");
    scanf(" %c", &color1);
    printf("Enter Color 2 (r,g,b,y,o): ");
    scanf(" %c", &color2);
    switch(color1){  //Printing the colors using switch case and if statements.
    case 'r':
    if (color2=='g'|| color2=='G'){
    enum Color c1 = RED;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='b'|| color2=='B'){
    enum Color c1 = RED;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='o'|| color2=='o'){
    enum Color c1 = RED;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='y'|| color2=='Y'){
    enum Color c1 = RED;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='r'|| color2=='R'){
    enum Color c1 = RED;
    enum Color c2 = RED;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    break;
    
    case 'g':
    if (color2=='g'|| color2=='G'){
    enum Color c1 = GREEN;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='r'|| color2=='R'){
    enum Color c1 = RED;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='b'|| color2=='B'){
    enum Color c1 = BLUE;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='o'|| color2=='O'){
    enum Color c1 = ORANGE;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='y'|| color2=='Y'){
    enum Color c1 = RED;
    enum Color c2 = GREEN;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    break;
    
    case 'b':
    if (color2=='g'|| color2=='G'){
    enum Color c1 = GREEN;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='r'|| color2=='R'){
    enum Color c1 = RED;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='b'|| color2=='B'){
    enum Color c1 = BLUE;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='o'|| color2=='O'){
    enum Color c1 = ORANGE;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='y'|| color2=='Y'){
    enum Color c1 = RED;
    enum Color c2 = BLUE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    break;
    
    case 'y':
    if (color2=='g'|| color2=='G'){
    enum Color c1 = GREEN;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='r'|| color2=='R'){
    enum Color c1 = RED;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='b'|| color2=='B'){
    enum Color c1 = BLUE;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='o'|| color2=='O'){
    enum Color c1 = ORANGE;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='y'|| color2=='Y'){
    enum Color c1 = RED;
    enum Color c2 = YELLOW;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    break;
    
    case 'o':
    if (color2=='g'|| color2=='G'){
    enum Color c1 = GREEN;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='r'|| color2=='R'){
    enum Color c1 = RED;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='b'|| color2=='B'){
    enum Color c1 = BLUE;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='o'|| color2=='O'){
    enum Color c1 = ORANGE;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    
    if (color2=='y'|| color2=='Y'){
    enum Color c1 = RED;
    enum Color c2 = ORANGE;
    enum Color mixed_color = colorMixer(c1, c2, mix_colors);
    control(mixed_color);
    }
    break;
        
    }

return 0;
}
int part3(){   //PART3
int invalid_move(int row, int col) {  //The invalid_move function warns the user if they make an invalid move.
int finish=0;
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        finish=1;
    }
    return finish;
}
void printing(char board[][3]){  //Printing the current move.
int i, j;
printf("\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int status(char board[3][3]){  //Controls if the board is filled or not.
int row,column,answer;
	answer = 1;
	for (row=0; row<3; ++row){
		for (column=0; column<3; ++column){
			if (board[row][column] == '_'){
				answer = 0;
			}
		}
	}
return (answer);
}

int check_winner_x(char board[3][3]) {  //Checks if the user X has won or not.
int i, j, answer=0;
for (i = 0; i < 3; i++) {
        if (board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
        printf("Player 1 (X) wins!");
        answer=1;
        }
        if (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
        printf("Player 1 (X) wins!");
        answer=1;
        }
        }
if (board[0][0] == 'X' && board[0][0] == board[1][1] && board [1][1] == board[2][2]){
	printf("Player 1 (X) wins!");
	answer=1;
	}
if (board[0][2] == 'X' && board[0][2] == board[1][1] && board [1][1] == board[2][0]){
	printf("Player 1 (X) wins!");
	answer=1;
	}      


return answer;
}

int check_winner_o(char board[3][3]) {
int i, j, answer=0;
for (i = 0; i < 3; i++) {   //Checks if user O has won or not.
        if (board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]){
        printf("Player 2 (O) wins!");
        answer=1;
        }
        if (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]){
        printf("Player 2 (O) wins!");
        answer=1;
        }
}
if (board[0][0] == 'O' && board[0][0] == board[1][1] && board [1][1] == board[2][2]){
	printf("Player 2 (O) wins!");
	answer=1;
	}
if (board[0][2] == 'O' && board[0][2] == board[1][1] && board [1][1] == board[2][0]){
	printf("Player 2 (O) wins!");
	answer=1;
	}      

return answer;

}

int i, j, row, column, choice, exit=0, finish=0, answer=0, a=0, b=0, c=0;
char board[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };

while(exit==0){  //Welcoming the user.Using exit==0 to show the menu again once the game is over.
finish=0,c=0,a=0; 
char board[3][3] = { {'_', '_', '_'}, {'_', '_', '_'}, {'_', '_', '_'} };//Declaring finish as 0 and the board like the beginning to be able to play again.
printf("\nWelcome to Tic-Tac-Toe!\n");
printf("1)Play!\n");
printf("2)Exit.\n");
scanf("%d", &choice);
switch(choice){
//Switch-case statements for the menu choice.
case 1:
while(finish==0){  //Using finish==0 to keep getting inputs from the user unless finish==1.
printf("Player 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);

while (board[row][column] != '_'){
while(board[row][column] == 'O' || board[row][column] == 'X'){
printf("\nThat cell is not available!Try another one!\n");  //If the cell is not available program warns the user and asks for a move again.
printf("\nPlayer 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);
while(c==0){
a=invalid_move(row,column);
if (a==1){
printf("\nPlease make a valid move.\n");  //If a==1 user is warned and asked for a move once again.
printf("\nPlayer 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);
}
else{
c=1;
}
}
}
}
c=0;
a=0;
while(c==0){
a=0;
a=invalid_move(row,column);
if (a==1){
printf("\nPlease make a valid move.\n");  //If a==1 user is warned and asked for a move once again.
printf("\nPlayer 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);
}
else{
c=1;
}
}
c=0;
a=0;
board[row][column]='X'; 
printing(board);
b=status(board);
if(b==1){  //If b==1 the board is filled.It ends in a tie.
printf("The board is filled.Tie!\n");
finish=1;
break;
}
answer=check_winner_x(board);
if(answer==1){
finish=1;
break;
}


printf("Player 2 (O),enter your move (row, col):");
scanf("%d %d", &row, &column);

while (board[row][column] != '_'){
while(board[row][column] == 'O' || board[row][column] == 'X'){
printf("\nThat cell is not available!Try another one!\n");
printf("\nPlayer 2 (O),enter your move (row, col):");
scanf("%d %d", &row, &column);

while(c==0){
a=invalid_move(row,column);
if (a==1){
printf("\nPlease make a valid move.\n");  //If a==1 user is warned and asked for a move once again.
printf("\nPlayer 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);
}
else{
c=1;
}
}
}
}
c=0;
a=0;
while(c==0){
a=0;
a=invalid_move(row,column);
if (a==1){
printf("\nPlease make a valid move.\n");  //If a==1 user is warned and asked for a move once again.
printf("\nPlayer 1 (X),enter your move (row, col):");
scanf("%d %d", &row, &column);
}
else{
c=1;
}
}


board[row][column]='O';
printing(board);
b=status(board);
if(b==1){
printf("The board is filled.Tie!\n");
finish=1;
break;
}
answer=check_winner_o(board);
if(answer==1){
finish=1;
break;
}

}


break;

case 2:  //If 2 is input by the user the program sends a goodbye message and exits.
printf("Have a good day!\n");
exit=1;
break;

default:   //If the user enters an invalid menu option they are warned and asked for a choice once again.
printf("Please make a valid menu choice.(1-2)");

}
}
return 0;
}


























