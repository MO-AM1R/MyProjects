/**
 * Represents a shopping item in a shopping cart.
 */

package ShoppingCart;
import Products.Product;

public class ShoppingItem {
    private final Product Item;
    private int quantity;

    /**
     * Constructs a new shopping item with the specified product and quantity.
     *
     * @param item the product associated with this shopping item
     * @param quantity the quantity of the product in this shopping item
     */
    public ShoppingItem(Product item, int quantity) {
        this.quantity = quantity;
        this.Item = item;
    }

    /**
     * Prints information about this shopping item to the console.
     */
    public void print() {
        System.out.println(quantity + " of -> " +
                Item.getInfo().getName() + "\nPrice of one unit\\Kilo -> " + Item.getInfo().getPrice()) ;
    }

    /**
     * Returns the quantity of the product in this shopping item.
     *
     * @return the quantity of the product in this shopping item
     */
    public int getQuantity() {
        return quantity;
    }

    /**
     * Returns the ID of the product associated with this shopping item.
     *
     * @return the ID of the product associated with this shopping item
     */
    public int getId() {
        return Item.getInfo().getId() ;
    }

    /**
     * Adds the specified quantity to the quantity of the product in this shopping item.
     *
     * @param quantity the quantity to add
     */
    public void addQuantity(int quantity) {
        this.quantity += quantity ;
    }
}
