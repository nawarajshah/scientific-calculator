#include<stdio.h>
#include<string.h>

// Defining arthematic function
float add(float,float);
float sub(float,float);
float mult(float,float);
float div(float,float);

int main() {
	float operand[10];
	int i,j,ctr,a,b;
	char raw[50],operators[9],tempOper[10][10];

	// Enter series of operation	
	printf("Enter your addition operation: ");
	scanf("%s",raw);
	
	// Spliting raw operation into operands and operators
    j=0; ctr=0;
    for(i=0;i<(strlen(raw));i++)
    {
    	// Assigning operator in operators string array
        if(raw[i]=='+'||raw[i]=='-'||raw[i]=='*'||raw[i]=='/')
        {
            operators[ctr]=raw[i];
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else // if condition false then assign the caracter as number in temporary operator
        {
            tempOper[ctr][j]=raw[i];
            j++;
        }
    }

	// Converting tempOper number into integer
	for(i=0;i<=ctr;i++) 
		operand[i] = atoi(tempOper[i]);

	// Performing math operation by calling respective function
    for(i=0;i<(strlen(operators));i++) {
    	switch(operators[i]) {
    		case '+':
    			operand[i+1] = add(operand[i],operand[i+1]);
    			break;
    		case '-':
    			operand[i+1] = sub(operand[i],operand[i+1]);
    			break;
			case '*':
    			operand[i+1] = mult(operand[i],operand[i+1]);
    			break;
			case '/':	
    			operand[i+1] = div(operand[i],operand[i+1]);
    			break;
		}
    	//printf("\n Operators: %c",operators[i]);
	}    
	
	// Final Result
	printf("\n operand: %.1f",operand[ctr]);
	
   //for(i=0;i<=ctr;i++)
    //printf("\n operand: %.3f",operand[i]);
		
	return 0;
}

float add(float a,float b) {
	return a+b;
}

float sub(float a,float b) {
	return a-b;
}

float mult(float a,float b) {
	return a*b;
}

float div(float a,float b) {
	return a/b;
}
