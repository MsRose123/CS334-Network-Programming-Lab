
import java.awt.*;
import java.applet.*;
/*
<applet code="AppletOne" width=350 height=350> </applet>
*/
public class AppletOne extends Applet {
public void paint(Graphics g) {
setBackground(Color.green);
g.setColor(Color.black);
g.drawString("Hello World", 20, 20);
}
}
