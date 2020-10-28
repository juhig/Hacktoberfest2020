<#
Cologne phonetics (also Kölner Phonetik, Cologne process) is a phonetic algorithm
which assigns to words a sequence of digits, the phonetic code.
The aim of this procedure is that identical sounding words have the same code
assigned to them. The algorithm can be used to perform a similarity search
between words. For example, it is possible in a name list to find entries
like "Meier" under different spellings such as "Maier", "Mayer", or "Mayr".
The Cologne phonetics is related to the well known Soundex phonetic algorithm
but is optimized to match the German language. The algorithm was published in
1969 by Hans Joachim Postel.

see at https://en.wikipedia.org/wiki/Cologne_phonetics
or https://de.wikipedia.org/wiki/K%C3%B6lner_Phonetik
#>

function colognehonetics {
    param(
        [string]$string
    )

    $result = ''
    If (!([string]::IsNullOrEmpty($string))){

        $character_list = @()
        
        $lastmatch = ''
 
        $string = $string.Trim().ToUpper()
 
        # Replace umlauts
        # Adjust if necessary i. e. Ć to C
        $string = $string.Replace('ß', 'S')
        $string = $string.Replace('Ä', 'AE')
        $string = $string.Replace('Ö', 'OE')
        $string = $string.Replace('Ü', 'UE')
        $string = $string.Replace('É', 'E')
 
        # Convert string to array
        for($i = 0; $i -lt $string.Length; $i++){
            $character_list += $string.Substring($i, 1)
        }
        $character_list = [System.Collections.Generic.List[System.Object]]($character_list)
 
        # processing initial sounds
        if ($character_list[0] -eq 'C') {
            if (@('A'; 'H'; 'K'; 'L'; 'O'; 'Q'; 'R'; 'U'; 'X').Contains($character_list[1])) {
                $result += '4'
            } else {
                $result += '8'
            }
            $character_list.RemoveAt(0)
        }
 
        # check all remaining characters of the word
        while ($character_list.Count) {
            # A, E, I, J, O, U, Y = 0
            if (@('A'; 'E'; 'I'; 'J'; 'Y'; 'O'; 'U').Contains($character_list[0])) {
                $result += '0'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # B = 1
            } elseif ($character_list[0] -eq 'B') {
                $result += '1'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # P before H = 1
            # P = 3
            } elseif ($character_list[0] -eq 'P') {
                if ($character_list[1] -and $character_list[1] -eq 'H') {
                    $result += '3'
                } else {
                    $result += '1'
                }
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # D, T before C, S, Z = 8
            # D, T = 2
            } elseif (@('D'; 'T').Contains($character_list[0])) {
                if ($character_list[1] -and @('C'; 'S'; 'Z').Contains($character_list[1])) {
                    $result += '8'
                } else {
                    $result += '2'
                }
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # F, V, W = 3
            } elseif (@('F'; 'V'; 'W').Contains($character_list[0])) {
                $result += '3'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # C before A, H, K, O, Q, U, X = 4
            # C after S, Z = 8
            } elseif ($character_list[0] -eq 'C') {
                if (@('S'; 'Z').Contains($lastmatch)) {
                    $result += '8'
                } elseif ($character_list[1] -and @('A'; 'H'; 'K'; 'O'; 'Q'; 'U'; 'X').Contains($character_list[1])) {
                    $result += '4'
                } else {
                    $result += '8'
                }
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # G, K, Q = 4
            } elseif (@('G'; 'Q'; 'K').Contains($character_list[0])) {
                $result += '4'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # X not after C, K, Q = 48
            # X after C, K, Q = 8
            } elseif ($character_list[0] -eq 'X') {
                if (@('C'; 'K'; 'Q').Contains($lastmatch)) {
                    $result += '8'
                } else {
                    $result += '48'
                }
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # L = 5
            } elseif ($character_list[0] -eq 'L') {
                $result += '5'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # M, N = 6
            } elseif (@('M'; 'N').Contains($character_list[0])) {
                $result += '6'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # R = 7
            } elseif ($character_list[0] -eq 'R') {
                $result += '7'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # S, Z = 8
            } elseif (@('S'; 'Z').Contains($character_list[0])) {
                $result += '8'
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
                continue
            # No match
            } else {
                $lastmatch = $character_list[0]
                $character_list.RemoveAt(0)
            }
        }

        $dataPattern = '(\d)\1+'
        $regesresult = $result | Select-String $dataPattern -AllMatches

        foreach($r in $regesresult.Matches.Value){
            $result = $result.Replace($r, $r.Substring(0, 1))
        }

        $result = $result.Substring(0, 1) + ($result.Substring(1, $result.Length - 1)).Replace('0', '')
    }
     return $result
}

# Test with strings
Write-Host (colognehonetics -string "Meier") # => 67
Write-Host (colognehonetics -string "Maier") # => 67
Write-Host (colognehonetics -string "Mayer") # => 67
Write-Host (colognehonetics -string "Mayr") # => 67

Write-Host (colognehonetics -string "Hacktoberfest") #04217382
