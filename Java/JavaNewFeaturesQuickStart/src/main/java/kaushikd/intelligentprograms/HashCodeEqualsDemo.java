package kaushikd.intelligentprograms;

import java.util.Date;

class Transaction {
    private String custId;
    private Date date;
    private double amount;

    public Transaction(String c, Date d, double a) {
        custId = new String(c); date = (Date) d.clone(); amount = a;
    }

    private int hashCode;
    @Override
    public int hashCode() {
        int result = hashCode;
        if (result == 0) {
            result = 17;
            result = result * 31 + custId.hashCode();
            result = result * 31 + date.hashCode();
            // result = result * 31 + ((Double) amount).hashCode();
            result = result * 31 + Double.hashCode(amount);
            hashCode = result;
        }
        return result;
    }

    @Override
    public boolean equals(Object x) {
        if (this == x) return true;
        if (x == null) return false;
        if (this.getClass() != x.getClass()) return false;
        Transaction t = (Transaction) x;

        return this.custId.equals(t.custId)
                && this.date.equals(t.date)
                && this.amount == t.amount;
    }
}

public class HashCodeEqualsDemo {
    public static void main(String[] args) {
        Date d = new Date();
        Transaction t1 = new Transaction("kaushik", d, 50000.00);

        Transaction t2 = new Transaction("kaushik", d, 50000.00);
        System.out.println("t1(" + t1.hashCode() + ") == t2(" + t2.hashCode() + ")? " + t1.equals(t2));
    }
}
