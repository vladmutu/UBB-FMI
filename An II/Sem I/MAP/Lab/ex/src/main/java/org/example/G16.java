package org.example;

import java.util.TreeSet;


class Student {
    String name;
    int varsta;

    Student(int v) {
        varsta = v;
    }

    Student(String n, int v) {
        name = n;
        varsta = v;
    }

    @Override
    public String toString() {
        return name + " " + varsta;
    }
}


public class G16 {
    public static void main(String[] args) {
        TreeSet<Integer> i = new TreeSet<Integer>();
        TreeSet<Student> s = new TreeSet<Student>((x, y) -> x.varsta - y.varsta);
        s.add(new Student("S", 19));
        s.add(new Student("D", 20));
        s.add(new Student("M", 19));
        i.add(1);
        i.add(2);
        i.add(1);
        System.out.println(s + " " + i);
    }
}


