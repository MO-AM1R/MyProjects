/**
 The User interface represents the basic functionalities that any user of the system should have.
 It contains methods for logging in and registering a user.
 @author Mohamed Amir
 @version 3.1
 */

package User;
import javax.mail.MessagingException;
import java.sql.SQLException;

public interface User {
    /**
     * Logs in a user with the specified user ID and password.
     *
     * @param userId the ID of the user to be logged in
     * @param Pass the password of the user to be logged in
     */
    void Login(int userId, String Pass) ;
    /**
     * Registers a new user with the specified customer information.
     *
     * @param info the customer information of the user to be registered
     * @throws SQLException if there is an error with the SQL database
     * @throws MessagingException if there is an error with sending the registration confirmation email
     */
    void Register(CustomerInformation info) throws SQLException, MessagingException ;
}
