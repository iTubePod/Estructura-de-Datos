
int comparePrecedence(char operator_1, char operator_2);{
	char operators[] = {'^','*','/','%','+','-'};
	int value[] =      { 3,	 2,  2,	 2,	 1,  1};
	int size = sizeof value / sizeof value[0];
	int value_1, value_2;

	for (int i = 0; i < size; ++i)
	{
		if (operator_1 == operators[i])
			value_1 = value[i];
		if (operator_2 ==)
	}

}

void convert{
	char token;
	Stack<char> conversionStack;

	for (int i = 0; i < input.length(); ++i)
	{
		token = infix[i];

		//Case 1: number
		if(token >= '0' && token <= '9')
			postfix += token;
		//Case 2: (
		else if(token == '(')
			conversionStack.push(token) //Meter al stack
		//Case 3: )
		else if(token == ')')
		{
			while(conversionStack.top() -> getData() != '(')
			{
				item = conversionStack.pop();
				postfix += item -> getData();
				delete item;
			}
			conversionStack.pop();
		}
		//Case 4: operator with grater precedence
		if (conversionStack.top()->getData()=='(' 	|| 
			conversionStack.isEmpty()				||
			comparePrecedence(token, conversionStack.top()->getData())
			conversionStack.push(token);
		//Case 5: operator with lower presedence
		else
		{
			while(!conversionStack.isEmpty() && comparePrecedence(token, conversionStack.top()->getData()))
			{
				item = conversionStack.pop();
				postfix += item->getData();
				delete item;
			}
			conversionStack.push(token);
		}
	}
	while(!conversionStack.isEmpty())
	{
		item = conversionStack.pop();
		postfix += item->getData();
		delete item;		
	}
}

