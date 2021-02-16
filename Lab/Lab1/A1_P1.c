#include <stdio.h>

//declared as global variables for the CharInput method
char letter;
int num = 0;
int length;
int count = 0;
int yesNum = 0;

void CharInput(){

	if(num != length){
		//if condition to check the number of characters left to be inserted is not zero
		scanf("%c", &letter);
		num++;	
		
		if(letter == 'b'){
			if(count == 0 || count == 3){
				count++;
				if(count == 4){
					//to check if the string pattern has been matched
					yesNum++;
					if(yesNum == 1){
					    printf("YES %d", num-3);
					}
					else{
					    printf(" %d", num-3);
					    
					}
					count = 1;//changed to 1 so as to check for the pattern again
					CharInput();
				}
				CharInput();//recurrsive call
			}
			else{
				//if b comes out of pattern then the count is started all over again
				count = 1;
			}
			CharInput();//recurrsive call
				
		}
		else{
			if(count == 1 || count == 2)
			{
				count++;
				CharInput();
			}
			
			else if(count == 3){
				count = 0;
				CharInput();
			}
			
			else
			{
			    
			   	CharInput();
			}
		}
			
	}

}


void main(){
	
	scanf("%d\n", &length);//input for the number of characters in the string
	CharInput();//recurrsive function call
	
	if(yesNum == 0){
	    printf("NO");
	}
}

