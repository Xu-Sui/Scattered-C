//PostfixExpressionCalculateFunctions.c

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100
char space = ' ';
char end = '\0';

typedef struct stackNode {
	union {
		double num;
		char signal;
	};
	struct stackNode* next;
}Node;

typedef struct stackTitle {
	char* postfixExpression;
	bool numOrSignal;
	Node* top;
}Title;

void stackInit(Title* title) {
	title->postfixExpression = (char*)calloc(MAX, sizeof(char));
	title->numOrSignal = false;
	title->top = NULL;
}

void stackPush(Title* title, void* data) {
	Node* push = (Node*)calloc(1, sizeof(Node));
	push->next = title->top, title->top = push;
	if (title->numOrSignal)
		push->num = *(double*)data;
	else
		push->signal = *(char*)data;
}

void stackPop(Title* title, void* data) {
	if (!title->top)
		exit(-1);
	if (title->numOrSignal)
		*(double*)data = title->top->num;
	else
		*(char*)data = title->top->signal;
	Node* oldtop = title->top;
	title->top = title->top->next;
	free(oldtop);
}

void stackNodeFree(Title* title) {
	struct des {
		double des1;
		char des2;
	}des0;
	while (title->top)
		stackPop(title, title->numOrSignal ? &des0.des1 : &des0.des2);
}

void stackFree(Title* title) {
	free(title->top);
}

int signalClass(char signal) {
	switch (signal) {
	case '(': case '+': case '-': return 1; break;
	case '*': case '/': return 2; break;
	case '^': return 3; break;
	case ')': return INT_MAX; break;
	default: exit(-2);
	}
}

void expIn(Title* title, char data) {
	int len = (int)strlen(title->postfixExpression);
	title->postfixExpression[len + 1] = end;
	title->postfixExpression[len] = data;
}

void inToPost(Title* title, char* exp) {
	if (!title || !exp)
		exit(-3);
	title->numOrSignal = false;
	char des;
	for (int i = 0; exp[i] != end; i++) {
		if (isdigit(exp[i]) || exp[i] == '.') {
			expIn(title, exp[i]);
			continue;
		}
		else {
			expIn(title, space);
			int val1 = signalClass(exp[i]);
			int val2 = title->top != NULL ? signalClass(title->top->signal) : 0;
			if (val1 == INT_MAX) {
				while (title->top->signal != '(')
					stackPop(title, &des), expIn(title, des), expIn(title, space);
				stackPop(title, &des);
				continue;
			}
			if (val1 < val2 || exp[i] != '(')
				for (; val1 <= val2 && title->top->signal != '('; val2 = title->top != NULL ? signalClass(title->top->signal) : 0)
					stackPop(title, &des), expIn(title, des), expIn(title, space);
			stackPush(title, &exp[i]);
		}
	}
	expIn(title, space);
	while (title->top != NULL)
		stackPop(title, &des), expIn(title, des), expIn(title, space);
}

double postCalc(Title* title) {
	if (!title)
		exit(-4);
	title->numOrSignal = true;
	for (int i = 0; title->postfixExpression[i] != end; i++) {
		double deal;
		if (title->postfixExpression[i] == space)
			continue;
		if (isdigit(title->postfixExpression[i])) {
			deal = strtod(&title->postfixExpression[i], &title->postfixExpression);
			stackPush(title, &deal);
			i = 0;
		}
		else {
			double val1, val2;
			stackPop(title, &val2), stackPop(title, &val1);
			switch (title->postfixExpression[i]) {
			case '+':
				deal = val1 + val2;
				break;
			case '-':
				deal = val1 - val2;
				break;
			case '*':
				deal = val1 * val2;
				break;
			case '/':
				deal = val1 / val2;
				break;
			default:
				exit(-5);
			}
			stackPush(title, &deal);
		}
	}
	double ret;
	stackPop(title, &ret);
	return ret;
}

void Calculator(char* exp) {
	Title* title = (Title*)malloc(sizeof(Title));
	stackInit(title);
	inToPost(title, exp);
	printf("Postfix Expression: %s\n", title->postfixExpression);
	stackNodeFree(title);
	printf("Expression = %g\n", postCalc(title));
	stackNodeFree(title);
	stackFree(title);
	free(title);
}

int main() {
	char* exp = (char*)calloc(50, sizeof(char));
	printf("Expression >> ");
	scanf("%s", exp);
	Calculator(exp);
	
	//debug example
	//exp = "1 2 3 4 5";
	/*double one = 0.0;
	for (int i = 0; exp[i] != end; ) {
		if (isdigit(exp[i]))
			one = strtod(exp + i, &exp), i = 0;
		else {
			i++;
			continue;
		}
		printf("%lf\n", one);
	}*/
	return 0;
}