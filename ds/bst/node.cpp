class Node{
    public:
        int value;
        int count;
        Node *left;
        Node *right;

        Node(){
            value = -1;
            count = 0;
            left = nullptr;
            right = nullptr;
        }

        Node(int inValue){
            value = inValue;
            count = 1;
            left = nullptr;
            right = nullptr;
        };

        void SetLeft(int newValue){
            left = new Node(newValue);
        }

        void SetRight(int newValue){
            right = new Node(newValue);
        }  
};