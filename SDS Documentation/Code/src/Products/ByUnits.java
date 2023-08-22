/**
 * The `ByUnits` class implements the `UnitType` interface for products sold by units.
 * It defines the maximum amount of units that can be purchased.
 */

package Products;
public class ByUnits implements  UnitType {
    /**
     * Returns the maximum amount of units that can be purchased.
     *
     * @return the maximum amount of units that can be purchased
     */
    public int getMaxAmount(){
        return 50;
    };


}
