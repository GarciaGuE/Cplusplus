#include "counter.h"


//Check if the value is between min and max
void Counter::Value(){
	value_ = (value_ > max_) ? max_ : (value_ < min_) ? min_ : value_;
}

//Overload operators
Counter Counter::operator=(const int &value){
	operations.push_back(value_);
	value_=value;
	Value();
	return this->value_;
}

Counter Counter::operator=(const Counter &c){
	operations.push_back(value_);
	value_=c.value_; 
	min_=c.min_; 
	max_=c.max_;
	return this->value_;
}

Counter Counter::operator++(void){
	operations.push_back(value_);
	value_++;
	Value();
	return this->value_;
}

Counter Counter::operator++(int){
	Counter aux=this->value_;
	operations.push_back(value_);
	value_++;
	Value();
	return aux;
}

Counter Counter::operator--(void){
	operations.push_back(value_);
	value_--;
	Value();
	return this->value_;
}

Counter Counter::operator--(int){
	Counter aux=this->value_;
	operations.push_back(value_);
	value_--;
	Value();
	return aux;
}

Counter Counter::operator+(const int &numero){
	Counter c(value_, min_, max_);
	operations.push_back(value_);
	c.value_+=numero;
	c.Value();
	return c;
}

Counter operator+(const int &numero, const Counter &c){
	Counter op(c);
	op.value_+=numero;
	op.Value();
	return op;
}

Counter Counter::operator-(const int &numero){
	Counter c(value_, min_, max_);
	operations.push_back(value_);
	c.value_-=numero;
	c.Value();
	return c;
}

Counter operator-(const int &numero, const Counter &c){
	Counter op(c);
	op.value_=numero-op.value_;
	op.Value();
	return op;
}

//Undo operations
bool Counter::undo(int n){
	if((n>(int)operations.size())|| n<1)
		return false;
	else{
		for(int i=0; i<n; i++){
			value_=operations.back();	
			operations.pop_back();
		}
		return true;
	}
}
