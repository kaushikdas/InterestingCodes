package com.kaushik.spring.basics.sprintinsimplesteps;

import org.springframework.stereotype.Component;

public class BubbleSortImpl implements SortAlgorithm {
  public void sort(int[] a) {
    int n = a.length;

    for (int i = 0; i < n-1; i++) {
      for (int j = 0; j < n-i-1; j++) {
        if (a[j] > a[j+1]) {
          int temp = a[j];
          a[j] = a[j+1];
          a[j+1] = temp;
        }
      }
    }
  }
}
