package CoinCounter.test;

import CoinCounter.src.CoinCounter;
import CoinCounter.src.CoinType;
import java.math.BigDecimal;
import java.util.ArrayList;
import org.junit.Assert;
import org.junit.Test;

public class CoinCounterTest {


    @Test
    public void shouldReturnOneWhenValueIsOne() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.ONE_LARGE);
        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(1.00)));
    }

    @Test
    public void shouldUseOneFiftyWhenValueIsFifty() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.FIFTY_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(50.00)));
    }

    @Test
    public void shouldUseOneTwentyWhenValueIsTwenty() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(20.00)));
    }

    @Test
    public void shouldUseOneTwentyAndOneFiftyWhenValueIsSeventy() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.FIFTY_NOTE);
        result.add(CoinType.TWENTY_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(70.00)));
    }

    @Test
    public void shouldUseTwoTwentyWhenValueIsForty() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TWENTY_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(40.00)));
    }

    @Test
    public void shouldUseTenAndTwentyWhenValueIsThirty() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TEN_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(30.00)));
    }

    @Test
    public void shouldUseTenTwentyAndFiveWhenValueIsThirtyFive() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TEN_NOTE);
        result.add(CoinType.FIVE_NOTE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(35.00)));
    }

    @Test
    public void shouldWorkWhenValueIsThirtySeven() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TEN_NOTE);
        result.add(CoinType.FIVE_NOTE);
        result.add(CoinType.TWO_LARGE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(37.00)));
    }

    @Test
    public void shouldWorkWhenValueIsThirtyNine() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TEN_NOTE);
        result.add(CoinType.FIVE_NOTE);
        result.add(CoinType.TWO_LARGE);
        result.add(CoinType.TWO_LARGE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(39.00)));
    }

    @Test
    public void shouldWorkWhenValueIsThirtyEight() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TEN_NOTE);
        result.add(CoinType.FIVE_NOTE);
        result.add(CoinType.TWO_LARGE);
        result.add(CoinType.ONE_LARGE);

        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(38.00)));
    }

    @Test
    public void shouldWorkWhenValueIsFortyNineNinetyNine() {
        CoinCounter coinCounter = new CoinCounter();

        ArrayList<CoinType> result = new ArrayList<>();
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.TWENTY_NOTE);
        result.add(CoinType.FIVE_NOTE);
        result.add(CoinType.TWO_LARGE);
        result.add(CoinType.TWO_LARGE);
        result.add(CoinType.FIFTY);
        result.add(CoinType.TWENTY);
        result.add(CoinType.TWENTY);
        result.add(CoinType.FIVE);
        result.add(CoinType.TWO);
        result.add(CoinType.TWO);


        Assert.assertEquals(result, coinCounter.calculateChange(BigDecimal.valueOf(49.99)));
    }






}
