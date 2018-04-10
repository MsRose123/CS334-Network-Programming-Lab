import java.io.Console;
import java.util.Properties;
import javax.mail.*;
import javax.mail.internet.*;

public class SMTP {
    public static void main(String[] args) {

        Console console = System.console();
        String host = "smtp.gmail.com";
        final String user = console.readLine("Enter senders mail id: ");
        final String password = new String(console.readPassword("Enter mail password: "));
        String to = console.readLine("Enter receivers mail id: ");

        //Get the session object
        Properties props = new Properties();
        props.put("mail.smtp.host",host);
        props.put("mail.smtp.auth", "true");
        props.put("mail.smtp.socketFactory.port", "465");
        props.put("mail.smtp.prot", "465");
        props.put("mail.smtp.socketFactory.class", "javax.net.ssl.SSLSocketFactory");

        Session session = Session.getDefaultInstance(
            props,
            new javax.mail.Authenticator()
            {
                protected PasswordAuthentication getPasswordAuthentication()
                {
                    return new PasswordAuthentication(user,password);
                }
            });

        //Compose the message
        try
        {
            MimeMessage message = new MimeMessage(session);
            message.setFrom(new InternetAddress(user));
            message.addRecipient(Message.RecipientType.TO,new InternetAddress(to));
            message.setSubject("SMTP Test");
            message.setText("This is simple program of sending email using JavaMail API");

            //send the message
            Transport.send(message);

            System.out.println("Message sent successfully...");

        }
        catch (MessagingException e)
        {
            e.printStackTrace();
        }
    }
}
