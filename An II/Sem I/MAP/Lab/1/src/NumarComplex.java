public class NumarComplex {
    private double re;
    private double im;

    @Override
    public String toString() {
        return ""+
                re +
                im +
                "i";
    }

    public NumarComplex(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public void adunare(NumarComplex nr) {
        this.re += nr.re;
        this.im += nr.im;
    }

    public void scadere(NumarComplex nr) {
        this.re -= nr.re;
        this.im -= nr.im;
    }

    public void inmultire(NumarComplex nr) {
        double aux = this.re;
        this.re = this.re * nr.re - this.im * nr.im;
        this.im = aux * nr.im + this.im * nr.re;
    }

    public void impartire(NumarComplex nr) {
        double auxre = this.re;
        double auxim = this.im;
        this.re = (this.re * nr.re + this.im * nr.im) / (nr.re * nr.re + nr.im * nr.im);
        this.im = (auxim * nr.re - auxre * nr.im) / (nr.re * nr.re + nr.im * nr.im);
    }
    //(a+bi)/(c+di) = (a+bi)*(c-di)/(c^2+d^2) = (ac-adi+bci+bd)/(c^2+d^2) -> re = (ac+bd)/(c^2+d^2) im = (-adi+bci)/(c^2+d^2)
    //(a+bi)*(c+di) = ac+adi+bci-bd
}
