select
    count(*) AS COUNT
from
    ECOLI_DATA
where
    (GENOTYPE & 2) != 2
    and ((GENOTYPE & 1) = 1 or (GENOTYPE & 4) = 4)