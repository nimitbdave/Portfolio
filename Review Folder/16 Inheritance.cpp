//This is a comment.

/*
multi-line
*/

//Libraries

#include <iostream>
#include <vectors>
#include <string>
#include <fstream>

using namespace std

//Functions

//What makes an object an object?  
class Animal{
  // Attributes: height weight variables  //These attributes will be modeled in the variables.  
  // Capabilities : Run Eat functions / methods, 
  
  //encapsulation.  (for protection)
  //will have some of these things be private (only changeable by functions inside of my class).  
  private: 
    int height; 
    int weight; 
    string name; 
    
    //static means this will be shared by every object of type Animal that is ever created. 
    //generally attributes that the class object (Animal) would not have.  
    //doesn't make sense that an Animal can count.  
    //Want to count the number of animals, but do not want the Animal type to be able to do it.  
    static int numOfAnimals; //i want to keep track of the number of animals created in my class.  
  
  
  /also encapsulation, keeping data protected.  
  public:  //need public methods to be able to access the values inside of there.  
    int getHeight()   { return height; }  //whenever this is called, it is going to return whatever value
                                        //is stored for my animal object to whoever calls for it.  
    int getWeight()   { return weight; }   
    string getName()  { return name; }
    void setHeight(int cm)  { height = cm; } //Only want them to enter a reasonable height.  
    void setWeight(int kg)  { weight = kg; }
    void setName(string animalName)    { name = animalName; }
    
//    void setAll(int, int, string); //declare a prototype
    Animal(int, int, string); //constructor, name starts with the class's name.  
                              //this is the fxn which will be called whenever an object is created. 
    ~Animal() //destructor [needed if there's a constructor]
    
    //prototype 
    Animal(); //another constructor which doesn't receive anything.  
              //OVERLOADING.  Name can be the same, but attributes need to be different.  
              //Anything marked as protected will be available to the same Class, 
              //as well as subclasses, but nothing else.  
    
    //define a STATIC METHOD
    //set aside bc they are attached to the Class, and not to the object.  
    //this method will return the number of animals that are created.  
    static int getNumOfAnimals() { return numOfAnimals; }  //no prototype, just do what it does.  
    void toString();  //will print out all the information we have on the animals.  
};

int Animal::numOfAnimals = 0;   //Our static number of animals, and how we refer to static variables
                                //as with the class name (Animal) followed by 2 colons (::)
                                //and then its name (numOfAnimals).  
                                //It's tied to the class.  It has nothing to do with the object itself.  

//We could then define setAll, since above is just the prototype method.    
//void Animal::setAll(int height, int weight, string name){    
        //Define exactly what is being passed in here.
        //height, weight, name
        //To refer to an object's specific height 
        //and not just a generic type of height 
        //you put "this" inside here.  
        //The reason we have to do that is because
        //whenever the Class is created there are no animal objects created,
        //so if we want to refer to the specific animal objects's value/version of height
        //we need to put "this" in front of it.  
//  this -> height = height; 
  //Do same thing for weight and name.  
//  this -> weight = weight; 
//  this -> name = name; 
  //Can also change that static variable, using ++.   
//  Animal::numOfAnimal++;    
}    

//Once again, going to do this with a constructor, as well.  
//A constructor is called every single time an animal object is created.  
Animal::Animal(int height, int weight, string name){
  this -> height = height;   
  this -> weight = weight; 
  this -> name = name; 
  Animal::numOfAnimal++;
  //Therefore, setAll does the same thing that the constructor does.  
  //So, no need to keep lines 70-87, setAll constructor.  
}

//Need to make a deconstructor.  
Animal::~Animal(){
  cout << "Animal " << this -> name << " destroyed << endl;  
    //create a message, get the name using "this", plus "destroyed". 
}

//Our OVERLOADED constructor which will be called when no attributes are passed in.  
Animal::Animal(){
    //In this situation, we could also call line 95, that we have created another animal.
  Animal::numOfAnimal++;  
}
  
  //Then we have toString(), line 65.  Let's declare that.  
  //void toString() will print out all the information we have on the animals. 
void Animal::toString(){ 
  cout << this -> name << " is " << this -> height <<
      " cms tall and " << this -> weight << " kgs in weight" << endl; 
  //Now we can go down to main() and start creating the Animal object.  
}

//INHERITANCE STARTS HERE.  
//Create a new dog class.  
//To inherit all the Animal classes, just need ": public Animal".  
//This way, we have everything that is defined in the Animal class.  
class Dog : public Animal{
  
  private: 
    string sound = "Woof"; 
  
  public:     //do some different things...
    void getSound() { cout << sound << endl; }
    Dog(int, int, string, string);  //prototype 
    Dog() : Animal(){};   //declare a default constructor (Dog()) which won't receive anything
                          //and on top of that, call the default super-class constructor (Animal)
    void toString();      //Then, we could decide to overwrite toString()
                          //Then, printing out the dog sound.  
};    //remember to place a semicolon at the end of a class.  VERY IMPORTANT.  
  
//We need to define everything that is going to change.  
//Constructor for the dog (Dog::Dog)
//Then get passed the (int height, int weight, string name, string bark)
//Now, to reference the Animal class, put a colon (:), 
//Now, we're going to say that we want the Animal constructor to handle the (height, weight, name)
//However, I want, for this constructor, to be able to handle the sound part, (this -> sound)
//because sound doesn't exist in the Animal class.  Here we will have it be "bark" (= bark;). 
//Some attributes will be shared (height, weight, name)
//and just change the one that's different (this -> sound = bark;) 
Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name){   
  
  this -> sound = bark; 

}

//Also could come in here since toString() also changed, so let's go in here and change it.  
//And, because the attributes (name, height, weight) were PRIVATE in Animal,
//I will have to use the GET method to be able to access them.  
void Dog::toString(){
  
  cout << this -> getName() << " is " << this -> getHeight() << 
    " cms tall and " << this -> getWeight() << " kgs in weight and says " 
    << this -> sound; 
    //Now we can demonstrate this by creating a Dog object, called spot.  
  
}

int main() {
  
  Animal fred; 
  
  fred.setHeight(33);   //set his height to 33
  fred.setWeight(10); 
  fred.setName("Fred"); 
  
  //Now can get the values back from it by...
  //NOTE:  We are not using "this ->" here.  
  //That is the difference between getting the information within the Class itself
  //and outside in main().  
  cout << fred.getName() << " is " << fred.getHeight() << 
    " cms tall and " << fred.getWeight() << " kgs in weight" << endl; 
  
  //We could then use our constructor in this situation.  
  //On line 123, we are using the default constructor which does NOT get any attributes.  
  //Here, we will use the constructor which DOES get attributes.  
  Animal tom(36, 15, "Tom"); 
  
  //Now we can print out all the differences between Tom and Fred.  
  cout << tom.getName() << " is " << tom.getHeight() << 
    " cms tall and " << tom.getWeight() << " kgs in weight" << endl; 
  //Error correction:  void setName( [should be string] animalName)... and [name] = animalName.  
  
  /*
  
  Output:
  Fred is 33 cms tall and 10 kgs in weight
  Tom is 36 cms tall and 15 kgs in weight
  Animal Tom destroyed    //Destructor called to destroy both objects since no longer needed.  
  Animal Fred destroyed
  
  */
  
  Dog spot(38, 16, "Spot", "Woof");   //Spot and sound will be "Woof" [notice, not "bark"]
  //Also, can demonstrate using static methods here:  
  //To call a static method, you can say "getNumOfAnimals()".
  //Can also get sound of Dog Spot (getSound).  
  //Can also call the Superclass version of a Method (spot.Animal::toString();)
  cout << "Number of Animals " << Animal::getNumOfAnimals() << endl; 
  
  spot.getSound(); 
  
  tom.toString();   //test toString, which basically does what all the other stuff did up there.  
  spot.toString(); 
  
  spot.Animal::toString();   //Superclass version of a Method, "::" is technically the scope operator.  
  
  return 0;
  
  /*
  
  Output:
  Fred is 33 cms tall and 10 kgs in weight
  Tom is 36 cms tall and 15 kgs in weight
  Number of Animals 3
  Woof
  Tom is 36 cms tall and 15 kgs in weight
  Spot is 38 cms tall and 16 kgs in weight and says Woof
  Spot is 38 cms tall and 16 kgs in weight
  Animal Spot destroyed    
  Animal Tom destroyed
  Animal Fred destroyed
  
  */

}
