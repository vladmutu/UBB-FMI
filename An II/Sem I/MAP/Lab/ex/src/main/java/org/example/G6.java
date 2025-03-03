package org.example;

import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Callable;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

class Pizza {
    protected int id;
    public Pizza(int id) {
        this.id = id;
    }
    public Pizza() {

    }
    public boolean equals(Pizza obj) {
        return obj.id ==this.id;
    }
} //end Pizza class
class PizzaWithCheese extends Pizza {
    private String topping;
    public PizzaWithCheese(int id,String topping) {
        super(id);
        this.topping=topping;
    }
    public boolean equals(PizzaWithCheese obj) {
        return super.equals(obj) && this.topping.equals(obj.topping);
    }
}


public class G6 { 
    public static void main(String[] args) { 
        PizzaWithCheese pizza1 = new PizzaWithCheese(1, "mozzarella"); 
        PizzaWithCheese pizza2 = new PizzaWithCheese(1, "feta"); 
        Pizza pizza3 = new PizzaWithCheese(1, "burduf"); 
        Pizza[] x={pizza1,pizza2}; 
        System.out.print(pizza1.equals(pizza2) +" "); 
        System.out.print(x[0].equals(x[1]) +" "); 
        System.out.print(pizza3.equals(pizza2) +" "); 
    } 
}



