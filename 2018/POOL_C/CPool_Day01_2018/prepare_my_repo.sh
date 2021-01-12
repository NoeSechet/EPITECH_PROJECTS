#!/bin/bash
blih -u noe-lam-anh.sechet@epitech.eu repository create "$1"
blih -u noe-lam-anh.sechet@epitech.eu repository setacl "$1" ramassage-tek r
blih -u noe-lam-anh.sechet@epitech.eu repository getacl "$1"
