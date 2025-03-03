package Factory;

import Container.Container;
import Enums.Strategy;

public interface Factory {
    Container createContainer(Strategy strategy);
}
