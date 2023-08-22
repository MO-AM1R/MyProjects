/**

 The UnitType interface defines a method for getting the maximum amount of a product that can be added to a shopping cart
 based on the unit type.
 */

package Products;
public interface UnitType {
    /**
     * Returns the maximum amount of a product that can be added to a shopping cart based on the unit type.
     *
     * @return The maximum amount of a product that can be added to a shopping cart
     */
    int getMaxAmount();

}
