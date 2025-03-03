public class ExpressionFactory {
    private static ExpressionFactory instance;

    private ExpressionFactory() {
    }

    public static ExpressionFactory getInstance() {
        if (instance == null) {
            instance = new ExpressionFactory();
        }
        return instance;
    }

    public ComplexExpresion createExpression(Operation operation, NumarComplex[] args) {
        switch (operation) {
            case ADDITION -> {
                return new OperatieAdaugare(args);
            }
            case SUBSTRACTION -> {
                return new OperatieScadere(args);
            }
            case DIVISION -> {
                return new OperatieImpartire(args);
            }
            case MULTIPLICATION -> {
                return new OperatieInmultire(args);
            }
            default -> {
                return null;
            }
        }
    }
}