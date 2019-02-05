#define N 4
 
typedef struct {
          int strike;
          int ball;
} Result;
 
// API
extern Result query(int guess[]);


void doUserImplementation(int guess[]) {

	Result temp;
	int number[10];
	for (int i = 0; i < 10; i++)
		number[i] = 0;

	guess[0] = 0;
	guess[1] = 1;
	guess[2] = 2;
	guess[3] = 3;
	while (1)
	{
		temp=query(guess);
		if (temp.strike == 4)
			break;
		else
		{
			if (!temp.ball)
			{
				for (int i = 0; i < 4; i++)
					number[guess[i]] = -1;
			}

			else if (temp.strike)
			{


			}

		}

	}

	
          // Implement a user's implementation function
          //
          // The array of guess[] is a return array that
          // is your guess for what digits[] would be.
}

