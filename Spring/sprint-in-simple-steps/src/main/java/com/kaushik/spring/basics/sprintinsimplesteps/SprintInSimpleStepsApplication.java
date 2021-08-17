package com.kaushik.spring.basics.sprintinsimplesteps;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.context.ConfigurableApplicationContext;

@SpringBootApplication
public class SprintInSimpleStepsApplication {


  public static void main(String[] args) {

    SpringApplication.run(SprintInSimpleStepsApplication.class, args);
    SearchAlgorithm algo = new BinarySearchImpl(new BubbleSortImpl());

    boolean isFound = algo.search(new int[] {50, 30, 10, 20, 60, 40}, 20);
    System.out.println("isFound = " + isFound);

  }

}
