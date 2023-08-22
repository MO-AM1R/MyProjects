/**

 The Customer class implements the User interface and represents a customer in the system.
 It contains information about the customer, their orders, and their shopping cart.
 The class provides methods for logging in, registering, logging out, adding products to cart, checking out, paying for orders,
 printing customer information, cart, and orders, and getting and setting customer orders and cart.
 @author Mohamed Amir
 @version 3.1
 */

package User;
import Database.*;
import Orders.*;
import Products.*;
import ShoppingCart.*;
import javax.mail.MessagingException;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.Map;

public class Customer implements User{
    private CustomerInformation info ;
    private Map<Integer, Order> orders = new HashMap<>();
    private boolean LoggedIn ;
    private ShoppingCart cart ;

    /**
     Logs in a customer with the specified user id and password. If the user is already logged in,
     an error message is printed.
     @param userId - the id of the customer to be logged in
     @param Pass - the password of the customer to be logged in
     */
    @Override
    public void Login(int userId, String Pass) {
        if (!LoggedIn) {
            Control control = new Control();
            Customer temp = control.Login(userId, Pass);

            if (temp != null) {
                this.setInfo(temp.getInfo());
                this.setOrders(temp.getOrders());
                this.setCart(temp.getCart());

                java.lang.System.out.println("You Logged in successfully welcome " + info.getName() + " :)");
                LoggedIn = true;
            }
        }
        else{
            System.out.println("You already Logged in");
        }
    }

    /**
     Registers a new customer with the specified customer information. If the user is already logged in,
     an error message is printed.
     @param info - the information of the customer to be registered
     @throws SQLException - if an error occurs while registering the customer in the database
     @throws MessagingException - if an error occurs while sending the registration confirmation email
     */
    @Override
    public void Register(CustomerInformation info) throws SQLException, MessagingException {
        if(!LoggedIn) {
            Control control = new Control();
            Customer customer = control.Register(info) ;

            if(customer != null){
                LoggedIn = true ;
                System.out.println("You registered successfully welcome " + info.getName() + " :)");
                this.setCart(customer.getCart());
                this.setInfo(customer.getInfo());
            }
            else{
                System.out.println("You entered existing id");
            }
        }
        else{
            System.out.println("You already Logged in");
        }
    }

    /**
        Logs out the currently logged in customer. If no customer is logged in, an error message is printed.
     */
    public void Logout(){
        if (LoggedIn){
            String name = info.getName() ;
            info = null ;
            LoggedIn = false ;
            java.lang.System.out.println("You Logged out successfully good bye " + name);
        }
        else{
            System.out.println("You already Logged out");
        }
    }

    /**
     * Sets the customer's information.
     * @param Info The customer's information object.
     */
    public void setInfo(CustomerInformation Info){
        this.info = Info ;
    }

    /**
     * Returns the customer's information.
     * @return The customer's information object.
     */
    public CustomerInformation getInfo(){
        return info ;
    }

    /**
     * Prints the customer's information.
     */
    public void print() {
        System.out.print("\n") ;
        if (this.getInfo() != null) {
            info.print() ;
        }
        else{
            System.out.println("Can't see your information and you logged out");
        }
    }

    /**
     * Prints the products in the customer's shopping cart.
     */
    public void printCart(){
        if (cart != null) {
            cart.print();
        }
        else{
            System.out.println("Can't see your cart and you logged out");
        }
    }

    /**
     * Displays the catalog of products.
     */
    public void viewCatalog(){
        Catalog catalog = new Catalog() ;
        catalog.print();
    }

    /**
     * Adds a product to the customer's shopping cart.
     * @param pName The name of the product.
     * @param pCategory The category of the product.
     * @param pBrand The brand of the product.
     * @param quantity The quantity of the product to add.
     * @throws SQLException if there is a problem accessing the database.
     */
    public void AddToCart(String pName, String pCategory, String pBrand, int quantity) throws SQLException {
        if (!LoggedIn){
            System.out.println("Can't add products to cart and you logged out");
            return ;
        }
        if (this.getInfo().getStatus() == CustomerStatus.Suspended){
            System.out.println("Can't add products to cart and you Suspended");
            return ;
        }
        Catalog catalog = new Catalog() ;
        Product product = catalog.getProduct(pName, pCategory, pBrand) ;

        this.cart.addProduct(product, quantity) ;
    }

    /**
     * Returns the customer's shopping cart.
     * @return The customer's shopping cart.
     */
    public ShoppingCart getCart() {
        return this.cart ;
    }

    /**
     * Sets the customer's shopping cart.
     * @param cart The customer's shopping cart.
     */
    public void setCart(ShoppingCart cart) {
        this.cart = cart ;
    }

    /**
     * Checks out the customer's shopping cart.
     * @param tax The tax rate for the order.
     * @param deliveryAddress The delivery address for the order.
     * @throws SQLException if there is a problem accessing the database.
     */
    public void checkOut(double tax, Address deliveryAddress) throws SQLException {
        if (cart.isEmpty()){
            System.out.println("You can't make an order without cart");
            return;
        }

        Order order = new Order(tax, deliveryAddress) ;
        order.setOrder(this.cart.getItems(), cart.getTotalPrice()) ;
        orders.put(order.getId(), order) ;

        Control control = new Control() ;
        control.addOrder(order, info.getId()) ;
        control.RemoveCart(cart) ;
    }
    /**
     * Pays for an order.
     * @param payment The payment method to use.
     * @param Id The ID of the order to pay for.
     * @throws SQLException if there is a problem accessing the database.
     */
    public void payOrder(PaymentMethod payment, int Id) throws SQLException {
        if (!orders.containsKey(Id)){
            System.out.println("Id is invalid");
            return;
        }
        if(orders.get(Id).payOrder(payment)){
            Control control = new Control() ;
            control.updateOrderStatus(Id) ;
        }
    }

    /**
     * Prints the customer orders.
     */
    public void printOrders() {
        for (Order order :
                orders.values()) {
            order.printOrder();
            System.out.println("-----------------------------------");
        }
    }

    /**
     * Returns true if the specified order ID exists in the orders map.
     *
     * @param randomId the ID to check for
     * @return true if the ID exists, false otherwise
     */
    public boolean hasOrderId(int randomId) {
        return orders.containsKey(randomId) ;
    }

    /**
     * Sets the orders map to the specified value.
     *
     * @param orders the new orders map
     */
    public void setOrders(Map<Integer,Order> orders) {
        this.orders = orders ;
    }

    /**
     * Adds the specified order to the orders map, using the order's ID as the key.
     *
     * @param order the order to add
     */
    public void addOrder(Order order) {
        orders.put(order.getId(), order) ;
    }

    /**
     * Returns the total price of the order with the specified ID.
     *
     * @param id the ID of the order to get the price for
     * @return the total price of the order
     */
    public double getOrderPrice(int id) {
        return orders.get(id).getTotalPrice() ;
    }

    /**
     * Returns a map of all orders.
     *
     * @return a map of all orders
     */
    public Map<Integer,Order> getOrders() {
        return orders ;
    }
}
