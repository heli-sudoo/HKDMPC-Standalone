"""LCM type definitions
This file automatically generated by lcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

class opt_sol_lcmt(object):
    __slots__ = ["N", "contacts", "qdummy"]

    __typenames__ = ["int32_t", "int32_t", "float"]

    __dimensions__ = [None, ["N", 4], ["N", 12]]

    def __init__(self):
        self.N = 0
        self.contacts = []
        self.qdummy = []

    def encode(self):
        buf = BytesIO()
        buf.write(opt_sol_lcmt._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        buf.write(struct.pack(">i", self.N))
        for i0 in range(self.N):
            buf.write(struct.pack('>4i', *self.contacts[i0][:4]))
        for i0 in range(self.N):
            buf.write(struct.pack('>12f', *self.qdummy[i0][:12]))

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != opt_sol_lcmt._get_packed_fingerprint():
            raise ValueError("Decode error")
        return opt_sol_lcmt._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = opt_sol_lcmt()
        self.N = struct.unpack(">i", buf.read(4))[0]
        self.contacts = []
        for i0 in range(self.N):
            self.contacts.append(struct.unpack('>4i', buf.read(16)))
        self.qdummy = []
        for i0 in range(self.N):
            self.qdummy.append(struct.unpack('>12f', buf.read(48)))
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if opt_sol_lcmt in parents: return 0
        tmphash = (0x193f4d961a6767b2) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff) + (tmphash>>63)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if opt_sol_lcmt._packed_fingerprint is None:
            opt_sol_lcmt._packed_fingerprint = struct.pack(">Q", opt_sol_lcmt._get_hash_recursive([]))
        return opt_sol_lcmt._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

