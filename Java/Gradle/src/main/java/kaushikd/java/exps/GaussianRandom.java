package kaushikd.java.exps;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

public class GaussianRandom {
    public static void main(String[] args) {
        Logger logger = LoggerFactory.getLogger(GaussianRandom.class);

        logger.info("GaussianRandom");
        double u = Math.random();
        double v = Math.random();

        double r = Math.sin(2*Math.PI*v)*Math.sqrt(-2*Math.log(u));
        logger.info("Random number: " + r);
    }
}