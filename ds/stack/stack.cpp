class Stack {
    public: 
        int size;
        int top;
        int* items;

        Stack(int inSize){
            size = inSize;
            top = -1;
            items = new int[size];

        }

        int Peek(){
            if(top != -1){
                return items[top];
            } 
            return -1;
        }

        void Push(int newValue){
            top++;
            items[top] = newValue;
        }

        int Pop(){
            if (top == -1) {
                return 0;
            }
            int popValue = items[top];
            top--;
            return popValue;
        }

};