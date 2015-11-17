class MinStack {
public:
	std::vector<int> container;
	std::vector<int> minimum;
    void push(int x) {
        container.push_back(x);
        if (minimum.empty())
        	minimum.push_back(x);
        else
        {
        	if (minimum.back() > x)
        		minimum.push_back(x);
        	else
        		minimum.push_back(minimum.back());
        }
    }

    void pop() {
        container.pop_back();
        minimum.pop_back();
    }

    int top() {
        return container.back();
    }

    int getMin() {
        return minimum.back();
    }
};