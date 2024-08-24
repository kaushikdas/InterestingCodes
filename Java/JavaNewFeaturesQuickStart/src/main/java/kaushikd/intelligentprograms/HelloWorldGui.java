package kaushikd.intelligentprograms;

import javax.swing.*;
import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionListener;

public class HelloWorldGui {
    public static void main(String[] args) {
        JFrame frame = new JFrame("HelloWorldGui");
        frame.add(new HelloComponent("Hello world!"));
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(300, 300);
        frame.setVisible(true);
    }
}

class HelloComponent extends JComponent
        implements MouseMotionListener {
    String message;
    int x = 125, y = 95;

    HelloComponent(String message) {
        this.message = message;
        addMouseMotionListener(this);
    }

    @Override
    protected void paintComponent(Graphics g) {
        g.drawString(message, x, y);
    }

    @Override
    public void mouseDragged(MouseEvent e) {
        x = e.getX(); y = e.getY();
        repaint();
    }

    @Override
    public void mouseMoved(MouseEvent e) { }
}
