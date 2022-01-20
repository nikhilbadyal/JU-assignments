package ChannelDir;

import java.util.Comparator;

//
// Decompiled by Procyon v0.5.36
//

public class PacketComparator implements Comparator<Packet>
{
    @Override
    public int compare(final Packet packet, final Packet packet2) {
        if (packet.length< packet2.length) {
            return -1;
        }
        return 1;
    }
}
