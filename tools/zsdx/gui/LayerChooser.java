package zsdx.gui;

import javax.swing.*;
import zsdx.*;

/**
 * A combo box to selected a layer.
 */
public class LayerChooser extends JComboBox {

    /**
     * Creates a new layer chooser.
     */
    public LayerChooser() {
	super();
	addItem(new KeyValue(MapEntity.LAYER_LOW, "Low"));
	addItem(new KeyValue(MapEntity.LAYER_INTERMEDIATE, "Intermediate"));
	addItem(new KeyValue(MapEntity.LAYER_HIGH, "High"));
    }
    
    /**
     * Returns the currently selected layer.
     * @return the selected layer
     */
    public int getLayer() {
	
	KeyValue item = (KeyValue) getSelectedItem();
	return Integer.parseInt(item.getKey());
    }
    
    /**
     * Selects a layer in the list.
     * @param layer the layer to make selected
     */
    public void setLayer(int layer) {

	KeyValue item = new KeyValue(Integer.toString(layer), null);
	setSelectedItem(item);
    }    
}
