package main

import "fmt"

type employee struct {
	name string
	salary int
	position string
}
	
type company struct {	
	companyName string
	employees []employee
}


func main(){


	// Add three employee using the employee struct (e.g., emp1 := employee{"Amir",
	// 80000, "Full-Stack Developer"}

	// var emp1 employee
	// var emp2 employee
	// var emp3 employee

	emp1 := employee{"Amir",80000, "Full-Stack Developer"}
	emp2 := employee{"Yaqoob",10000, "Security Engineer"}
	emp3 := employee{"Saad",200000, "Cloud Architect"}
	
	fmt.Printf("Details\n %v\n",emp1)
	fmt.Printf(" %v\n",emp2)
	fmt.Printf(" %v\n",emp3)


	//Creating array of employees and adding the above employees in it. 

	employs:=[]employee{emp1,emp2,emp3}
	fmt.Printf("%v",employs)

	
	Facebook:=company{"Tetra", employs}

	fmt.Printf("\n\nThe Company Name: %v\n",Facebook.companyName)
	fmt.Printf("The Employees Details: %v",Facebook.employees)



}