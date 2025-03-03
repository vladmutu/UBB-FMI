public class Main {

    public static void main(String[] args) {
        ExpressionParser parser = new ExpressionParser(args);
        try{
            ComplexExpresion expr = parser.parse();
            NumarComplex result = expr.execute();
            System.out.println("Rezultatul expresiei este: " + result);
        }catch(RuntimeException e){
            System.out.println("Nu este o expresie de numere complexe");
        }
    }
}