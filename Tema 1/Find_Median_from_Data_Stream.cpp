class MedianFinder {
private:
    // Lungimea stream-ului la un moment dat in fiecare jumatate
    int first_size;
    int second_size;
    // Max heap pentru prima jumatate a stream-ului de date
    priority_queue<int> first_half;
    // Min heap pentru a doua jumatate a stream-ului de date
    priority_queue <int, vector<int>, greater<int>> second_half;

public:
    MedianFinder() {
        first_size = 0;
        second_size = 0;
    }

    // Unul dintre heap-uri are cu doua element mai mult decat celalalt
    void balanceGreaterFirst(int num){
        int element = first_half.top();
        first_half.pop();
        if(num <= element){
            first_half.push(num);
            second_half.push(element);
        }
        else{
            second_half.push(element);
            second_half.push(num);
            first_size--;
        }
        second_size++;
    }

    void balanceGreaterSecond(int num){
        int element = second_half.top();
        second_half.pop();
        if(num >= element){
            second_half.push(num);
            first_half.push(element);
        }
        else{
            first_half.push(element);
            first_half.push(num);
            second_size--;
        }
        first_size++;
    }

    void addNum(int num) {
        // Unul dintre heap-uri este gol
        if(first_half.empty()){
            first_half.push(num);
            first_size++;
            return;
        }
        if(second_half.empty()){
            if(first_half.top() > num){
                balanceGreaterFirst(num);
                return;
            }
            second_half.push(num);
            second_size++;
            return;
        }

        // Avem elemente in ambele heap-uri
        if(first_size == second_size){
            if(num > first_half.top()){
                second_half.push(num);
                second_size++;
                return;
            }
            first_half.push(num);
            first_size++;
            return;
        }
        if(first_size < second_size){
            if(num <= second_half.top()){
                first_half.push(num);
                first_size++;
                return;
            }
            balanceGreaterSecond(num);
            return;
        }
        if(first_size > second_size){
            if(num >= first_half.top()){
                second_half.push(num);
                second_size++;
                return;
            }
            balanceGreaterFirst(num);
            return;
        }
    }
    
    double findMedian() {
        if(first_size > second_size){
            return (double)first_half.top();
        }
        else if(first_size < second_size){
            return (double)second_half.top();
        }
        else{
            double result = (first_half.top() + second_half.top()) / 2.0;
            return result;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */