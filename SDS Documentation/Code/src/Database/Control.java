/**
 * The Control class provides a high-level interface for interacting with the system's database and performing various
 * actions, such as adding users, updating shopping carts, generating OTPs for user email confirmation, and more.
 */

package Database;
import EmailSender.EmailSender;
import Orders.Order;
import Products.*;
import ShoppingCart.*;
import User.*;
import javax.mail.MessagingException;
import java.sql.SQLException;
import java.util.*;

public class Control {

    /**
     * Checks whether a product with the given ID exists in the database.
     * @param id the ID of the product to check for
     * @return true if a product with the given ID exists in the database, false otherwise
     */
    public boolean existId(int id) {
        Database database = new Database();
        return database.exist(id);
    }

    /**
     * Checks whether a given product's quantity exceeds the maximum amount allowed by its unit type, is out of stock,
     * or exceeds the product's current available quantity.
     * @param product the product to check
     * @param quantity the quantity of the product to check
     * @return true if the product can be added to the cart, false otherwise
     */
    public boolean checkQuantity(Product product, int quantity){
        UnitType unitType = product.getInfo().getUnitType() ;

        if (quantity > unitType.getMaxAmount()){
            System.out.print("Can't add product upon " + unitType.getMaxAmount());
            if (unitType instanceof ByUnits){
                System.out.println(" Units");
            }
            else{
                System.out.println(" Kilos");
            }
            return false;
        }
        if (product.getInfo().getStatus() == Status.OutOfStock){
            System.out.println("This Product is out of stock");
            return false;
        }
        if (quantity > product.getInfo().getQuantity()){
            System.out.println("You exceeded quantity limit\nQuantity of this product -> " + product.getInfo().getQuantity());
            return false;
        }

        return true ;
    }

    /**
     * Checks whether a shopping cart with the given ID exists in the database.
     * @param id the ID of the shopping cart to check for
     * @return true if a shopping cart with the given ID exists in the database, false otherwise
     */
    public boolean existShoppingCartId(int id) {
        Database database = new Database();
        return database.existShoppingCartId(id);
    }

    /**
     * Adds a user to the database.
     * @param customer the customer object representing the user to add
     * @throws SQLException if an error occurs while executing the SQL statement
     */
    public void addUser(Customer customer) throws SQLException {
        Database database = new Database();
        database.addUser(customer);
    }

    /**
     * Generates a random integer.
     * @return a random integer
     */
    public int getRandom(){
        Random rand = new Random();
        return rand.nextInt(50);
    }

    /**
     * Registers a customer with the given customer information, including generating a unique shopping cart ID,
     * confirming the customer's email address via OTP, and adding the customer to the database.
     * @param info the customer information object to register
     * @return the registered customer, or null if registration failed
     * @throws MessagingException if an error occurs while sending the confirmation email
     * @throws SQLException if an error occurs while executing the SQL statement
     */
    public Customer Register(CustomerInformation info) throws MessagingException, SQLException {
        if (!this.existId(info.getId())) {
            int randomId;
            do {
                randomId = getRandom() ;
            } while (this.existShoppingCartId(randomId));

            ShoppingCart cart = new ShoppingCart(info.getId(), randomId);

            if(confirmEmail(info.getEmail())) {
                Customer customer = new Customer() ;
                customer.setInfo(info);
                customer.setCart(cart);
                addUser(customer);

                return customer;
            }
        }
        return null;
    }

    /**
     * Generates a random 8-digit OTP (one-time password).
     * @return a random 8-digit OTP
     */
    private String generateOTP() {
        StringBuilder OTP = new StringBuilder();
        for (int i =0; i < 8; ++i){
            Random rand = new Random();
            OTP.append(rand.nextInt(10));
        }
        return OTP.toString();
    }

    /**
     * Sends an OTP to the given email address and returns the OTP value.
     * @param Email the email address to send the OTP to
     * @return the OTP value
     * @throws MessagingException if an error occurs while sending the email
     */
    public String sendOTP(String Email) throws MessagingException {
        String OTP = generateOTP() ;

        EmailSender emailSender = new EmailSender() ;
        emailSender.sendEmail(Email, OTP);

        return OTP ;
    }

    /**
     * Prompts the user to enter an OTP and checks whether the entered OTP matches the generated OTP.
     * @param Email the email address to confirm
     * @return true if the entered OTP matches the generated OTP, false otherwise
     * @throws MessagingException if an error occurs while sending the confirmation email
     */
    public boolean confirmEmail(String Email) throws MessagingException {
        String requiredOTP, OTP ;

        for (int i = 0; i <= 5; ++i) {
            OTP = sendOTP(Email);

            System.out.println("An OTP sent to your email. enter it -> ");
            Scanner scanner = new Scanner(System.in) ;
            requiredOTP = scanner.nextLine() ;

            if (requiredOTP.equals(OTP)){
                return true ;
            }
            else{
                System.out.print("\nInvalid OTP The number of remaining attempts -> "+ (5 - i - 1) +"\n");
            }
        }
        return false ;
    }

    /**
     * Logs a user in with the given ID and password.
     * @param id the ID of the user to log in
     * @param pass the password of the user to log in
     * @return the logged-in customer object, or null if login failed
     */
    public Customer Login(int id, String pass) {
        Database database = new Database();

        if (this.existId(id)) {
            String temp = database.getPass(id);

            if (Objects.equals(temp, pass)) {
                return database.getCustomer(id);
            }
            else {
                System.out.println("Password is incorrect");
            }
        }
        else {
            System.out.println("Id is not exist");
        }

        return null;
    }

    /**
     * Loads all the products from the database.
     * @return a list of products.
     */
    public static List<Product> LoadProducts(){
        Database database = new Database() ;
        return database.getProducts() ;
    }

    /**
     * Retrieves the shopping cart for a given user ID.
     * @param userId the user ID of the shopping cart.
     * @return the shopping cart.
     */
    public ShoppingCart getCart(int userId) {
        Database database = new Database();
        return database.getCart(userId);
    }

    /**
     * Updates the quantity of a product in the database and the shopping cart.
     * @param product the product to update.
     * @param cart the shopping cart that contains the product.
     * @param quantity the new quantity of the product.
     * @throws SQLException if a database error occurs.
     */
    public void UpdateProduct(Product product, ShoppingCart cart, int quantity) throws SQLException {
        Database database = new Database();

        database.UpdateProducts(product, quantity);
        database.UpdateShoppingCart(cart);
        database.UpdateShoppingItems(product, quantity, cart);
    }

    /**
     * Generates a new unique order ID.
     * @return a unique order ID.
     */
    public int generateOrderId() {
        Database database = new Database() ;

        int randomId;
        do {
            randomId = getRandom() ;
        } while (database.existOrderId(randomId));

        return randomId ;
    }

    /**
     * Adds an order to the database for a given user ID.
     * @param order the order to add.
     * @param id the user ID of the order.
     * @throws SQLException if a database error occurs.
     */
    public void addOrder(Order order, int id) throws SQLException {
        Database database = new Database() ;
        database.addOrder(order, id);
    }

    /**
     * Removes all the items from a given shopping cart.
     * @param cart the shopping cart to remove items from.
     * @throws SQLException if a database error occurs.
     */
    public void RemoveCart(ShoppingCart cart) throws SQLException {
        Database database = new Database() ;
        database.resetCart(cart) ;
    }

    /**
     * Retrieves all the orders for a given user ID.
     * @param userId the user ID of the orders to retrieve.
     * @return a map of order IDs to orders.
     */
    public Map<Integer, Order> getOrders(int userId) {
        Database database = new Database() ;
        return database.getOrders(userId) ;
    }

    /**
     * Updates the status of an order in the database.
     * @param id the ID of the order to update.
     * @throws SQLException if a database error occurs.
     */
    public void updateOrderStatus(int id) throws SQLException {
        Database database = new Database() ;
        database.updateOrderStatus(id);
    }
}
