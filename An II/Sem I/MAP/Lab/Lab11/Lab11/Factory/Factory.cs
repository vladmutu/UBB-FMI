using Lab11.Enums;

namespace Lab11.Factory;
public interface Factory
{
    public Container.Container createContainer(Strategy containerStrategy);
}