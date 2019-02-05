#include <cstdio>

using namespace std;

//user variables that I used
int _N;
int chefs[33];; // min 1 to max 32 chefs. This will store the orderid of the food they're cooking.
int stack[10001]; //keeps track of orders from 1 to 10000
int top; //top of stack. initialized as -1.
int cookingtimes[10001]; //how long each dish takes to cook. cookingtime[3] is cooking time of order id 3.
int waitingtimes[10001]; //until when can the customer wait? -> calculated as epoch and not duration. In other words, if orderid is 265, cookingtime is 3, waitingtime is given as 4, and ordertime was 7, we will do : waitingtimes[265] = 7+4.
int progress[10001]; //keeps track of order status. It's initialized as 0, and increases every time it's cooked. In other words, if progress[265] is 3, it will be cooked from example above. However, if currenttime is 11 and progress is 2, the cooking failed because waitingtimes[265] is 10 and currenttime is 11, but progress is only 2 but cookingtime required is 3.
bool iscooking[10001];
int price[10001]; //keeps track of order price

void init(int N){//number of chefs
    _N = N;
    for(int i=1; i<=N; ++i){
        chefs[i] = -1; //make chefs do nothing(-1) in the start.
    }
    top = -1; //we don't need to clean the array stack[10001] physically. if top is -1, it's meaningless anyway.
}

void ordermenu(int orderid, int ordertime, int cookingtime, int waitingtime, int price){ //order id : 1~10000, ordertime : 0~19999, cookingtime : 1~19999, int waitingtime : 1~19999, int price : 1~1000
    stack[++top] = orderid; //put item in stack. Note : it's ++top. we increase the top first, and then put item in the new top. Empty top is -1, so it will go to stack[0] when empty.
    cookingtimes[orderid] = cookingtime;
    waitingtimes[orderid] = ordertime + waitingtime;  //note : we don't store ordertime in an array. We don't need it. All we need is the cooking time required, the progress we have on it so far, and until when can the customer wait.
    price[orderid] = price;
    progress[orderid] = 0; //init as 0 because we haven't cooked yet.
    iscooking[orderid] = false;
}

void tick(int currenttime){//called every epoch, from 0 to 19999.
    /*
    This code here will be written in pseudocode for convenience...
    remember, chefs[i] store orderid of the food they're cooking

    # 1 hour has passed. Find all the cooks that have been cooking an hour before, and increase the food's progress(++). And then, see if it's the required cooking time. If it is, call finishcook API and cleanup.
    for chef in chefs where chef != -1:
        if ++progress[chef] == cookingtimes[chef]:  # if the current progress of food is the required cooking time, call finishcook API, free chef, pop the order from interesting stack.
            finishcook(index of chef(1~32))
            chef = -1   # chefs are now free
            find chef in stack:
                stack.pop(chef)  #find the orderid from the stack, and remove it.
            iscooking[chef] = false #the food is no longer cooking

    # Now, we have already taken care of increasing the time of whatever food we've been cooking. We now have sort the stack so that we have top 32 performers.
    stack.sort() # sort stack so that stack[0] will have the worse performer, and stack[top] will have the best performer. The function to compare is : price[orderid] / (cookingtimes[orderid] - progress[orderid]) so that price is divided by required REMAINING cooking time.

    # Now that we have a stack that tells us the top 32 best dishes to cook, we allocate the dishes to chefs.
    for chef in chefs where chef == -1:  # find chefs that AREN'T cooking, and from top 32 stacks of dish, if that dish is not cooking(iscooking[orderid] == false), start cooking by using main API and set the bool to true.
        for top 32 orderid in stack:
            if iscooking[orderid] == false:
                chef = orderid
                startcook(index of chef(1~32))
                iscooking[orderid] = true
    
    # Now we have chefs that weren't doing anything changed to cooking something good in top 32 priority stacks.
    # However, it was for chefs that didn't have anything allocated.
    # What about chefs that started cooking something really really cheap but takes a long time in the previous currenttime-1? Can't we make him do something else?
    for chef in chefs where chef == 1:
        for top 32 orderid in stack:
            if iscooking[orderid] == false and price[chef] / (cookingtimes[chef] - progress[chef]) < price[orderid] / (cookingtimes[orderid] - progress[orderid]):
                #if the value of current orderid in top32 stack is better than whatever chef was cooking, it's obvious that we need to make him do this instead.
                iscooking[chef] = false   # update bool flag for that shitty dish
                chef = orderid
                startcook(index of chef(1~32))   # main API
                iscooking[orderid] = true   # update bool flag
    
    # Now, we made sure that chefs are working on the top 32 priority dishes 100%. The ones that weren't doing anything got them, the ones that were doing something bad that weren't included in top32 stack was changed to a better one in stack.
    # This is end of program. Each time tick(currenttime) is called, we will make best decisions given the current information.
    */
}

int main(){


    return 0;
}
