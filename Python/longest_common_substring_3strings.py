# Let there be three strings S1, S2 and S3. Find the largest common substring of 
# these three strings. 

def longest_common_substring(S1, S2, S3):
    m, n, p = len(S1), len(S2), len(S3)
    
    # Initialize DP table with all zero values
    dp = [[[0] * (p + 1) for _ in range(n + 1)] for __ in range(m + 1)]
    
    max_length = 0
    end_index = 0  # Stores end index in S1

    # Fill the DP table
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            for k in range(1, p + 1):
                if S1[i-1] == S2[j-1] == S3[k-1]:  # Matching characters
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1
                    if dp[i][j][k] > max_length:
                        max_length = dp[i][j][k]
                        end_index = i  # Store end index in S1

    # Extract the substring using end_index
    longest_substring = S1[end_index - max_length:end_index] if max_length > 0 else ""
    return longest_substring

test_cases = [
    ("abcdef", "zabxcdef", "qabxcdef", "cdef"),
    ("hello", "hello", "hello", "hello"),
    ("abc", "xyz", "pqr", ""),
    ("startXYZ", "start123", "startABC", "start"),
    ("123end", "xyzend", "pqrend", "end"),
    ("aXbYc", "dXeYf", "gXhYi", "Y"),
    ("abcdefghijklmno", "xyzabcdefghijk", "123abcdefghij", "abcdefghij"),
    ("HelloWorld", "helloworld", "HELLOWORLD", ""),
    ("a", "a", "a", "a"),
    ("xxABCDyy", "mmABCDnn", "ooABCDpp", "ABCD"),
]

for i, (s1, s2, s3, expected) in enumerate(test_cases, 1):
    result = longest_common_substring(s1, s2, s3)
    print(f"Test Case {i}: {'PASS' if result == expected else 'FAIL'}, Output: {result}")
