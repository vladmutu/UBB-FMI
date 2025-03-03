package org.example;

import java.util.TreeSet;

interface Formula {
    double calculate(double a);
}
class A implements Formula {
    static int var1 =100;
    double x=9;
    public double calculate(double a) {
        double x =A.this.var1*a;
        x++;
        double finalX = x;
        Formula f = (double b) -> {
            return Math.abs(finalX);
        };
        return f.calculate(a);
    }
}

public class R11 {
    public static void main(String[] args) { 
        System.out.printf("%.0f",new A().calculate(10)); 
    } 
}



