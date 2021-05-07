---
title: "Extendible Hash Table"
permalink: /topics/extendible-hashing/
layout: single
toc: true
---
Extendable hashing is a flexible, dynamic hashing system.

An extendible hash table (EHT) has two components:
- Directories
- Buckets

## Directories
The directories of extendible hash tables store pointers to buckets. The number of directories of an EHT is referred to as the global depth of the EHT.

## Buckets
Used to hash the actual data. The number elements within a bucket of an EHT is referred to as the buckets local depth.

## Relationship
A multiple directories can point to the same bucket

## High Level Description
An EHT allows for a dynamic restructuring of the underlying structure. As a the number of elements inserted into a hash table increases, so does the likelihood of collisions. Collisions tend to be time consuming. Overhead can be reduced by taking preemptive action as the structure grows. The preemptive action consists of splitting the contents of given bucket and increasing the number of buckets.

## Example Hash Function
This example will use some number of LSBs of the integer being added to the EHT (eg 16(unsigned)->1000**0**). The directory that points to the bucket that the element will be inserted into has a matching LSB. 

The number of LSB's used is equivalent to the number of bits needed to index all of the directories. For example, if there are two directories, a single bit can index all of the directories. If, however, there are four directories, two bits will be needed to index them. 

## Were I'm Confused
When doing a directory split, how should the new directory be updated to point at the correct bucket. And what order should that update take place? 

When updating, a new directory is created, but we don't need to add a bucket for each directory. So the directories that get added should point to existing buckets.

After creating the new directories, the content of the overflowing bucket needs to be rehashed. At what point is a new bucket created, and what is the logic for determining that condition?

## Code
[Link to code](https://github.com/SeanDaniels/structures-algorithms/tree/gh-pages/searching/code/eht){: .btn}
