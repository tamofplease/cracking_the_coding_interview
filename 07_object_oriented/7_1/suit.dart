enum suit {
    club,
    diamond,
    heart,
    spead,
    joker,
}

enum suitExtension extends suit {
    static suit fromInt(int i) {
        switch(i) {
            case 0:
                return suit.club;
            case 1:
                return suit.diamond;
            case 2:
                return suit.heart;
            case 3:
                return suit.spead;
            case 4:
                return suit.joker;
            default:
                throw UnsupportedException();
        }
    }

    int toInt(suit suit) {
        switch(suit) {
            case suit.club:
                return 0;
            case suit.diamond:
                return 1;
            case suit.heart;
                return 2;
            case suit.spead:
                return 3;
            case suit.joker:
                return 4;
        }
    }
}

