#include<stdio.h>
#include<time.h>
#include<string.h>
void speedTest( ){
    char passage[] = "lorem ipsum dolor sit amet, consectetur adipiscing elit. sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    char userInput[1000];
    int correct = 0,num_words = 0, i = 0;
    num_words++;
    clock_t start, end;
    double time_taken, speed;
    printf("Type the following passage:\n%s\n", passage);
    start = clock();
    fgets(userInput, 1000, stdin);
    end = clock();
    time_taken = ((double) (end - start)) / CLOCKS_PER_SEC;
    for( i ; passage[i] != '\0' && userInput[i] != '\0'; i++){
        if(userInput[i] == passage[i]){
            correct++;
        }
    }
    speed = (correct / (double)  num_words) * 60;
    printf("You typed %d words correctly in %.2f seconds\n", correct  , time_taken);
    printf("Your speed was %.2f words per minute\n", speed);

}

int main(){
    speedTest();
    // time_t Time =time(NULL);
    // char* Ctime = ctime(&Time);
    // printf("%s", Ctime);
  
    return 0;
}
