/**
 * The EmailSender class provides a method for sending an email message with an OTP code
 * to a specified email address. This class uses the JavaMail API to send the email message.
 */

package EmailSender;
import javax.mail.*;
import javax.mail.internet.*;
import java.util.Properties;

public class EmailSender {
    /**
     * The JavaMail session used to send the email message.
     */
    Session session ;

    /**
     * The email message to be sent.
     */
    Message message ;

    /**
     * Sends an email message with an OTP code to the specified email address.
     *
     * @param To The email address to which the message is sent.
     * @param OTP The OTP code to be included in the message body.
     * @throws MessagingException If an error occurs while sending the email.
     */
    public void sendEmail(String To, String OTP) throws MessagingException {
        EmailSender mail = new EmailSender() ;
        mail.setServerProperties() ;
        mail.send(To, OTP) ;
    }

    /**
     * Sends the email message to the specified email address.
     *
     * @param To The email address to which the message is sent.
     * @param OTP The OTP code to be included in the message body.
     * @throws MessagingException If an error occurs while sending the email.
     */
    private void send(String To, String OTP) throws MessagingException {
        String emailSubject = "Confirm your Email" ;
        String emailBody = "You must to confirm your email by this OTP " + OTP ;

        message = new MimeMessage(session);
        message.setRecipient(Message.RecipientType.TO, new InternetAddress(To));

        message.setFrom(new InternetAddress("mohamedamir5050@gmail.com"));
        message.setSubject(emailSubject);
        message.setText(emailBody);
        Transport.send(message);
    }

    /**
     * Sets the server properties for sending the email message.
     */
    private void setServerProperties() {
        Properties properties = new Properties();
        properties.put("mail.smtp.auth", true);
        properties.put("mail.smtp.starttls.enable", true);
        properties.put("mail.smtp.port", "587");
        properties.put("mail.smtp.host", "smtp.gmail.com");

        String username = "mohamedamir5050@gmail.com";
        String password = "rczcvhqlmrlsrgxd";

        session = Session.getInstance(properties, new Authenticator() {
            @Override
            protected PasswordAuthentication getPasswordAuthentication() {
                return new PasswordAuthentication(username, password);
            }
        });
    }
}