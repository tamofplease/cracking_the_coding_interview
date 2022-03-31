class Trump implement Card {

    const Trump(suit s, int n) : number = n, suit = s;

    int number;
    suit suit;

    @override
    int get setOfNumbers => 54;

    @override
    List<Card> generateAll() {
        List<Card> li = [];
        for(int i=1;i<=13;i++) {
            for(int j=0;j<4;j++) {
                suit s = suitExtension.fromInt(j);
                li.add(Trump(s, i));
            }
        }
        li.add(Trump(suit.joker, 0));
        li.add(Trump(suit.joker, 0));
        return li;
    }
}