package xiangqi;

import xiangqi.*;

public class Intersection {
    private Piece piece;
    private Position positionDebut;
    private Position positionArrivee;

    public Intersection() {
        this.piece = null;
        this.positionDebut = null;
        this.positionArrivee = null;
    }

    public Intersection(Position position) {
        this.positionDebut = position;
        this.positionArrivee = position;
        this.piece = null;
    }

    public Piece getPiece() {
        return piece;
    }

    public void setPiece(Piece piece) {
        this.piece = piece;
    }

    public Position getPositionDebut() {
        return positionDebut;
    }

    public Position getPositionArrivee() {
        return positionArrivee;
    }
}
