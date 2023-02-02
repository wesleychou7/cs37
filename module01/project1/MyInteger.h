class MyInteger{

    private:
        int myNum;

    public:
        explicit MyInteger(int num){
            myNum = num;
        }

        int get(){
            return myNum;
        }

        void set(int num){
            myNum = num;
        }

        void add(int num){
            myNum = myNum + num;
        }

        void subtract(int num){
            myNum = myNum - num;
        }

        void multiply(int num){
            myNum = myNum * num;
        }

        int compare(MyInteger myInteger){
            if (myNum < myInteger.get()){
                return 0;
            }
            if (myNum == myInteger.get()){
                return 1;
            }
            if (myNum > myInteger.get()){
                return 2;
            }
            
            return 999;
        }

};